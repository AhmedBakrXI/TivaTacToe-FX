import com.fazecast.jSerialComm.SerialPort;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class TicTacToe extends Application {

    public static SerialPort chosenPort;
    private final Cell[][] cell = new Cell[3][3];
    private final Label lblStatus = new Label("X's turn to play ...");
    private char whoseTurn = 'X'; // X starts playing
    private int focusedRow = 0;
    private int focusedCol = 0;
    private char lastPlayer = 'O'; // Initialize with 'O' since 'X' starts
    private String receivedData;

    public static void main(String[] args) {
        launch(args);   // launch the TicTacToe application
        chosenPort.closePort();
        System.out.println("Closed " + chosenPort);
    }

    @Override
    public void start(Stage primaryStage) {
        GridPane grid = new GridPane(); // Grid pane to display cells of the game

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid.add(cell[i][j] = new Cell(), j, i); // add cells to grid
            }
        }

        // Customize the status label
        lblStatus.setFont(Font.font("LCDMono2", FontWeight.BOLD, FontPosture.ITALIC, 36));
        lblStatus.setTextFill(Color.GREEN);

        VBox vbox = new VBox();
        vbox.getChildren().addAll(grid, lblStatus);
        Scene scene = new Scene(vbox, 500, 600);

        primaryStage.setScene(scene);
        primaryStage.setTitle("TicTacToe");
        primaryStage.getIcons().add(new Image("https://cdn-icons-png.flaticon.com/512/566/566294.png"));
        primaryStage.show();

        // Create a thread to continuously read from the console
        Thread consoleInputThread = new Thread(() -> {
            SerialPort[] serialPorts = SerialPort.getCommPorts();

            for (SerialPort port : serialPorts) {
                System.out.println("Available port: " + port.getSystemPortName());
            }
            String portName = "COM4"; // Replace with the name of the serial port you want to connect to

            chosenPort = SerialPort.getCommPort(portName);
            if (chosenPort.openPort()) {
                System.out.println("Connected to " + portName);
            } else {
                System.err.println("Failed to open " + portName);
                System.exit(1);
                return;
            }

            while (true) {
                try {
                    byte[] readBuffer = new byte[1024];
                    int numBytesRead = chosenPort.readBytes(readBuffer, readBuffer.length);
                    receivedData = new String(readBuffer, 0, numBytesRead);
                    if (receivedData.equals("A") || receivedData.equals("B")) {
                        cell[focusedRow][focusedCol].MC_handleSwitch();
                    }
                } catch (Exception e) {
                    // Ignore exception
                }
            }


        });

        consoleInputThread.setDaemon(true);
        consoleInputThread.start();

        cell[focusedRow][focusedCol].setFocusedd(true); // Initial focus on the first cell
    }

    // returns true if all cells have been clicked
    public boolean isFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cell[i][j].getToken() == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    // returns true if the token has won the game
    public boolean isWon(char token) {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (cell[i][0].getToken() == token && cell[i][1].getToken() == token && cell[i][2].getToken() == token) {
                return true;
            }
        }
        // Check columns
        for (int i = 0; i < 3; i++) {
            if (cell[0][i].getToken() == token && cell[1][i].getToken() == token && cell[2][i].getToken() == token) {
                return true;
            }
        }

        // Check diagonals
        if (cell[0][0].getToken() == token && cell[1][1].getToken() == token && cell[2][2].getToken() == token) {
            return true;
        }

        return cell[0][2].getToken() == token && cell[1][1].getToken() == token && cell[2][0].getToken() == token;
    }

    public class Cell extends StackPane {

        private final Text tokenText = new Text("");
        private char token = ' ';

        Cell() {
            this.setStyle("-fx-border-color: black");
            this.setPrefSize(200, 200);
            this.tokenText.setFont(Font.font("Bradley Hand ITC", FontWeight.EXTRA_BOLD, FontPosture.REGULAR, 80));
            this.getChildren().add(tokenText);
        }

        public void setFocusedd(boolean focused) {
            if (focused) {
                this.setStyle("-fx-border-color: blue; -fx-border-width: 3;");
            } else {
                this.setStyle("-fx-border-color: black; -fx-border-width: 1;");
            }
        }

        public void MC_handleSwitch() {

            if (receivedData.equals("A") || receivedData.equals("B")) {
                System.out.println("Received data: " + receivedData);

                Platform.runLater(() -> {
                    if (receivedData.equals("A")) {
                        setFocusedd(false); // Clear focus from the current cell

                        focusedCol++;
                        if (focusedCol >= 3) {
                            focusedCol = 0;
                            focusedRow++;
                            if (focusedRow >= 3) {
                                focusedRow = 0;
                            }
                        }

                        cell[focusedRow][focusedCol].setFocusedd(true); // Set focus on the new cell
                    } else if (receivedData.equals("B") && token == ' ' && whoseTurn != 'E' && whoseTurn != 'D') {
                        // Check whose turn it is
                        char currentPlayer = whoseTurn;

                        // Place the current token in the cell
                        setTokenText(currentPlayer);

                        this.token = currentPlayer;

                        if (isWon(currentPlayer)) {
                            lblStatus.setText(currentPlayer + " HAS WON !!");
                            lblStatus.setTextFill(Color.BLUE.brighter());
                            whoseTurn = 'E'; // Game ends
                        } else if (isFull()) {
                            lblStatus.setText("Draw !! The game is over.");
                            lblStatus.setTextFill(Color.GOLD.darker());
                            whoseTurn = 'D'; // Game ends
                        } else {
                            // Switch to the next player's turn
                            whoseTurn = (currentPlayer == 'X') ? 'O' : 'X';
                            lblStatus.setText(whoseTurn + "'s turn to play ...");
                            lblStatus.setTextFill((whoseTurn == 'X') ? Color.GREEN : Color.RED);
                        }
                    }
                });
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            } else {

            }

        }

        public void setTokenText(char turn) {
            this.tokenText.setText(String.valueOf(turn));
            if (turn == 'X') {
                this.tokenText.setFill(Color.GREEN);
            } else if (turn == 'O') {
                this.tokenText.setFill(Color.RED);
            }
        }

        public char getToken() {
            return token;
        }

    }
}

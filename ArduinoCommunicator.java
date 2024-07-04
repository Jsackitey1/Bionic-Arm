public class ArduinoCommunicator {
    import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

    public class ArduinoCommunicator {
        private static final String ARDUINO_IP = "192.168.8.140";
        private static final int ARDUINO_PORT = 80;

        public static void sendCommandToArduino(String command) {
            new Thread(() -> {
                try {
                    Socket socket = new Socket(ARDUINO_IP, ARDUINO_PORT);
                    PrintWriter out = new PrintWriter(
                            new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

                    out.println(command);
                    out.flush();

                    out.close();
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }).start();
        }
    }

}

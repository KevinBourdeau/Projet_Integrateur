
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;
import java.util.Enumeration;

/**
 * The SerialTest class
 * 
 * @author kevinBourdeau
 *
 */
public class SerialTest implements SerialPortEventListener {

	SerialPort serialPort;

	/** The port we’re normally going to use. */
	private static final String PORT_NAMES[] = { " /dev/tty.usbserial-A9007UX1 ", // Mac OS X
			" /dev/ttyUSB0 ", // Linux
			"COM18", // Windows
	};

	private BufferedReader input;
	@SuppressWarnings("unused")
	private OutputStream output;
	private static final int TIME_OUT = 2000;
	private static final int DATA_RATE = 9600;

	Car car;

	/**
	 * The constructor of the SerialTest
	 * 
	 * @param car
	 */
	public SerialTest(Car car) {
		this.car = car;
	}

	/**
	 * Initialize the serial port
	 * 
	 */
	public void initialize() {
		CommPortIdentifier portId = null;
		@SuppressWarnings("rawtypes")
		Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();

//First, Find an instance of serial port as set in PORT_NAMES.
		while (portEnum.hasMoreElements()) {
			CommPortIdentifier currPortId = (CommPortIdentifier) portEnum.nextElement();
			for (String portName : PORT_NAMES) {
				if (currPortId.getName().equals(portName)) {
					portId = currPortId;
					break;
				}
			}
		}
		if (portId == null) {
			System.out.println(" Could not find COM port. ");
			return;
		}

		try {
			serialPort = (SerialPort) portId.open(this.getClass().getName(), TIME_OUT);
			serialPort.setSerialPortParams(DATA_RATE, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,
					SerialPort.PARITY_NONE);

// open the streams
			input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
			output = serialPort.getOutputStream();

			serialPort.addEventListener(this);
			serialPort.notifyOnDataAvailable(true);
		} catch (Exception e) {
			System.err.println(e.toString());
		}
	}

	/**
	 * Close the listening of the serial port
	 * 
	 */
	public synchronized void close() {
		if (serialPort != null) {
			serialPort.removeEventListener();
			serialPort.close();
		}
	}

	/**
	 * Read the serial port of the arduino
	 * 
	 */
	public void serialEvent(SerialPortEvent oEvent) {
		if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
			try {
				String inputLine = null;

				/**
				 * Check if we can start to read
				 */
				if (input.ready()) {
					inputLine = input.readLine();

					@SuppressWarnings("unused")
					String[] chunks = inputLine.split(" , ");

					/**
					 * Check if there are message for nodes
					 */
					if (inputLine.contains("L12-")) {

						System.out.println(inputLine);

						if (inputLine.length() == 7) {
							System.out.println(inputLine.length());
							car.positionCar(Integer.parseInt(inputLine.substring(6)));
						}

						if (inputLine.length() == 8) {

							if (inputLine.indexOf(' ') == 5) {
								car.positionCar(Integer.parseInt(inputLine.substring(6)));
							}

							if (inputLine.indexOf(' ') == 6) {
								car.positionCar(Integer.parseInt(inputLine.substring(7)));
							}
						}

						if (inputLine.length() == 9) {
							car.positionCar(Integer.parseInt(inputLine.substring(7)));
						}

					}

//					try {
//						System.out.println(chunks[0] + " \t " + chunks[1] + " \t " + chunks[2] + " \t ");
//					} catch (Exception e) {
//					}

				}

			} catch (Exception e) {
				System.err.println(e.toString());
			}
		}
// Ignore all the other eventTypes, but you should consider the other ones.
	}

}

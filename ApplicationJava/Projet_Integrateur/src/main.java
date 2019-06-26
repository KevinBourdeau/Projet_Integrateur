/**
 * The Main class
 * 
 * @author kevinBourdeau
 *
 */
public class main {

	public main(String[] args) {
		// TODO Auto-generated method stub

		Car car = new Car(60, 443);

		Frame frm = new Frame(car);

		SerialTest main = new SerialTest(car);

		main.initialize();
		Thread t = new Thread() {
			public void run() {
				// the following line will keep this app alive for 1000 seconds,
				// waiting for events to occur and responding to them (printing incoming
				// messages to console).
				try {
					Thread.sleep(1000000);
				} catch (InterruptedException ie) {
				}
			}
		};
		t.start();
		System.out.println(" Started ");

	}
}

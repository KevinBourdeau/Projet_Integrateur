
import javax.swing.JFrame;

/**
 * The Frame class
 * 
 * @author kevinBourdeau
 *
 */
public class Frame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	Panel panel;
	Car car;

	/**
	 * The constructor of the Frame
	 * 
	 * @param car
	 */
	public Frame(Car car) {
		this.car = car;
		Panel panel = new Panel(this, car); // Instantiate a new panel
		// buildTheFrame();
		// TODO Auto-generated constructor stub
		setTitle("Suivi de la voiture");
		setSize(633, 553);
		setLocationRelativeTo(null);
		setResizable(false);
		setDefaultCloseOperation(3);
		setContentPane(panel);
		setVisible(true);
	}

}

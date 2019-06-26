
/**
 * The Panel class
 * 
 * @author kevinBourdeau
 *
 */
import java.awt.Graphics;
import java.awt.Image;

import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class Panel extends JPanel {

	private static final long serialVersionUID = 1L;
	Frame theFrame;
	Image theMap, theCar;
	Car car;

	/**
	 * Constructor of the Panel
	 * 
	 * @param framePanel
	 * @param car
	 * 
	 * 
	 */
	public Panel(Frame framePanel, Car car) {
		this.car = car;
		/* car.positionCar(); */

		// TODO Auto-generated constructor stub
		theFrame = framePanel;

		try {
			theMap = ImageIO.read(getClass().getResourceAsStream("MapTest.png")); /* Load the image */
			theCar = ImageIO.read(getClass().getResourceAsStream("Car.png"));

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * Draw the car
	 * 
	 * @param g
	 */
	public void paintComponent(Graphics g) {

		super.paintComponent(g);
		g.drawImage(theMap, 0, 0, theFrame);
		g.drawImage(theCar, car.getX(), car.getY(), theFrame);
		this.repaint();

	}

}



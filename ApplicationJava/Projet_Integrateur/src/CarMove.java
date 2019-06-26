/**
 * The Interface CarMove
 * 
 * @author kevinBourdeau
 *
 */
public interface CarMove {
	/**
	 * Get the position x of the car
	 * 
	 * @return the x
	 */
	public int getX();

	/**
	 * Set the position x of the car
	 * 
	 * @param x
	 */
	public void setX(int x);

	/**
	 * Get the position y of the car
	 * 
	 * @return the y
	 */
	public int getY();

	/**
	 * Set the position y of the car
	 * 
	 * @param y
	 */
	public void setY(int y);

	/**
	 * Place the car
	 * 
	 * @param pos
	 */
	void positionCar(int pos);
}

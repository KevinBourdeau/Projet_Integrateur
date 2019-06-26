/**
 * The Car class
 * 
 * @author kevinBourdeau
 *
 */
public class Car implements CarMove {

	public int x;
	public int y;
	int position [][] = {
			{1, 0, 5},
			{2, 1, 5},
			{3, 1, 4},
			{4, 3, 5},
			{5, 3, 4},
			{6, 5, 5},
			{7, 5, 2},
			{8, 5, 1},
			{9, 1, 1},
			{10, 6, 5},
			{11, 6, 2},
			{12, 6, 0},
			{13, 1, 0},
			{14, 0, 0},
			{15, 0, 2},
			{16, 0, 4}
			
			};
	int i, j;
	
	/**
	 * Constructor of the car
	 * @param x
	 * @param y
	 */
	public Car(final int x, final int y) {
		this.x = x;
		this.y = y;
	}

	/**
	 * Get the position x of the car
	 * @return the x
	 */
	@Override
	public int getX() {
		return x;
	}

	/**
	 * Set the position x of the car
	 * @param x
	 */
	@Override
	public void setX(int x) {
		this.x = x;		
	}

	/**
	 * Get the position y of the car
	 * @return the y
	 */
	@Override
	public int getY() {
		return y;
	}

	/**
	 * Set the position y of the car
	 * @param y
	 */
	@Override
	public void setY(int y) {
		this.y = y;
		
	}
	
	/**
	 * Place the car
	 * @param pos
	 */
	@Override
	public void positionCar(int pos) {
		
		for(int i=0; i<position.length; i++) {
			for(j=0; j<position[i].length; j++) {
				if (position[i][0] == pos) {
					//	System.out.println(position[i][1]);
						//System.out.println(position[i][2]);
						setX(60 + (position[i][1]) * 80);
						setY(443 - (position[i][2]) * 80);
					}
				
			}
		}
		
		
		
	}
	
	
}

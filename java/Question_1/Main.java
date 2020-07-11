import java.util.*;

public class Main{
	private static int intData;

	public static void main(String[] args){
		int isDone =  0;
		int menu;
		DoublyLinkedList dList = new DoublyLinkedList();

		while (isDone == 0){
			Scanner op = new Scanner(System.in);
			System.out.println("1. Insert integer element at front");
			System.out.println("2. Insert integer element at back");
			System.out.println("3. Remove integer element");
			System.out.println("4. Read first element in the list");
			System.out.println("5. Read last element in the list");
			System.out.println("6. Print list");
			System.out.println("7. Exit the menu");
			menu = op.nextInt();

			switch (menu){
				case 1:
					try{				
						System.out.println("Please insert the integer");
						Scanner input = new Scanner(System.in);
						intData = input.nextInt();
						dList.insertAtFront(intData);
					}
					//Number format exception
					catch(NumberFormatException e){
						System.err.println("Exception: " +e);
						System.err.println("Invalid data type, try again");
						System.out.println();
					}
					break;

				case 2:
					try{				
						System.out.println("Please insert the integer");
						Scanner input = new Scanner(System.in);
						intData = input.nextInt();
						dList.insertAtBack(intData);
					}
					catch(NumberFormatException e){
						System.err.println("Exception: " +e);
						System.err.println("Invalid data type, try again");
						System.out.println();
					}
					break;

				case 3:
					try{
						System.out.println("Choose the integer to be removed");
						Scanner input = new Scanner(System.in);
						intData = input.nextInt();
						dList.removedNode(intData);
					}
					catch(NumberFormatException e){
						System.err.println("Exception: " +e);
						System.err.println("Invalid data type, try again");
						System.out.println();
					}
					break;

				case 4:
					System.out.println("First element: " + dList.readFrontData());
					break;

				case 5:
					System.out.println("last element: " + dList.readLastData());
					break;

				case 6:
					dList.printList();
					System.out.println();
					break;

				case 7:
					System.out.println("Goodbye");
					isDone = 1;
					break;

				default:
					System.out.println("Invalid operation");

			}
		}
	}
}
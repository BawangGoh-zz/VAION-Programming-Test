/*
This class is used to define the node in the doubly linked list. A doubly linked list contain pointers to 
previous node and the next node.
Explanation:
1. Singly Linked List (SLL)
			 _______		 _______         _______        
			|	|	|	    |	|	|		|	|	|	
root -----> |	| o	|-----> |	| o |----->	|	| o	|-----> null
			|___|___|		|___|___|		|___|___|

2. Doubly Linked List (DLL)
			 ___________		 ___________         ___________        
root ----->	|   |	|	|----->	|   |	|	|----->	|	|	|	|	
 			| o |	| o	| 		| o |	| o |		| o	| 	| o |-----> null
null <-----	|___|___|___|<-----	|___|___|___|<-----	|___|___|___|
*/

public class ListNode{
	private int data;		// Contained int data
	private ListNode prev;		// Reference to next node
	private ListNode next;		// Reference to next nide

	/*
	 * Constrcutor for root node
	 * Set the self-reference of next and prev to null
	 *
	 * @param data node
	*/
	public ListNode(int data){
		this(null, data, null);
	}

	/*
	 * Constrcutor for node
	 *
	 * @param data node
	 * @param next reference to next node
	 * @param prev reference to previous node
	*/
	public ListNode(ListNode prev, int data, ListNode next){
		this.data = data;
		this.prev = prev;
		this.next = next;
	}

	// Getter and setter method for current node
	public int getData(){
		return data;
	}
	public void setData(int data){
		this.data = data;
	}

	// Getter and setter method for next node
	public ListNode getNext(){
		return next;
	}
	public void setNext(ListNode next){
		this.next = next;
	}

	// Getter and setter method for previous node
	public ListNode getPrev(){
		return prev;
	}
	public void setPrev(ListNode prev){
		this.prev = prev;
	}
}//end class ListNode
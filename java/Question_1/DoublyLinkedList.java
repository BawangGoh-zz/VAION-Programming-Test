/* Java Programming
Question 1: Implement a doubly linked list (of integers) class which allows new integers to be added 
either end of the list, any referenced node to be removed and the first and last integers to be read
euickly.
*/

public class DoublyLinkedList{
	private ListNode head;
	private ListNode tail;

	/*
	 * Default constructor for empty list
	*/
	public DoublyLinkedList(){
		this.head = null;
		this.tail = null;
	}

	/*
	 * Inserting a node at the front of list
	 *
	 * @param data node
	*/
	public void insertAtFront(int newData){
		// Check if the list is empty
		if (head == null)
			head = tail = new ListNode(newData);
		// There are already node existed
		else{
			ListNode newNode = new ListNode(null, newData, head);
			head.setPrev(newNode);
			head = newNode;
		}
	}

	/*
	 * Inserting a node at the end of list
	 *
	 * @param data node
	*/
	public void insertAtBack(int newData){
		// Check if the list is empty
		if (tail == null)
			head = tail = new ListNode(newData);
		else{
			ListNode newNode = new ListNode(tail, newData, null);
			tail.setNext(newNode);
			tail = newNode;
		}
	}

	/*
	 * Removed any referenced node
	 *
	 * @param data node
	*/
	public void removedNode(int delData){
		// CHeck if it is empty
		if (head == null || tail == null){
			head = tail = null;
		}

		ListNode currNode, prevNode;
		currNode = prevNode = head;

		// ALways start by forward searching the element
		while (currNode != null && currNode.getData() != delData){
			/* Previous node will stay at the (n)th and current node is always
			one step ahead of previous node at (n+1)th
			*/
			prevNode = currNode;
			currNode = currNode.getNext();
		}

		// Error case: Reference node not found
		if (currNode == null){
			System.out.println("Element is not found");
			return;
		}
		// Case 1: Only one element in the list
		else if (currNode.getPrev() == null && currNode.getNext() == null){
			head = currNode = null;
		}
		// Case 2: Removed element is first element
		else if (currNode == head && currNode.getNext() != null){
			head = currNode.getNext();
			currNode = head;
			currNode.setPrev(null);
		}
		// Case 3: Removed element in between
		else if (prevNode != null && currNode.getNext() != null){
			currNode = currNode.getNext();
			prevNode.setNext(currNode);
			currNode.setPrev(prevNode);
		}
		// Case 4: Removed the last element
		else{
			prevNode.setNext(null);
			tail = prevNode;
		}
	}


	/*
	 * Display the whole linked list in forward direction
	*/
	public void printList(){
		ListNode curr = head;
		
		// Check if it is an empty list
		if (head == null){
			System.out.println("List is empty");
			return;
		}

		// Doubly Linked list
		System.out.println("Integers in doubly linked list: ");
		while (curr != null){
			// Print the node by incrementing pointer
			System.out.print(curr.getData() + " ");
			curr = curr.getNext();
		}
	}

	/*
	 * Fast access to the first element
	 *
	 * @param int data
	*/
	public int readFrontData(){
		// Check if it is an empty list
		if (head == null){
			System.out.println("List is empty");
		}
		return head.getData();
	}

	/*
	 * Fast access to the last element
	 *
	 * @param int data
	*/
	public int readLastData(){
		// Check if it is an empty list
		if (tail == null){
			System.out.println("List is empty");
		}
		return tail.getData();
	}
}
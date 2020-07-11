# Python Programming
'''
Question 1: Define a generator which generate the positive integers up o and including the supplied value which 
are divisible by another supplied positive integer and use it to calculate the sum of all positive integers less
than 102030 which are divisible by 3
'''
def generator(x, div):
	'''Generator function that sum all the number less than x and divisible by div

	Args:
		x (int): Positive limit
		div (int): Divisor
	
	Return:
		sum: The sum of all the element in the array
	'''
	arr = []
	[arr.append(i) for i in range(1,x) if (i % div) == 0]

	return sum(arr)


'''
Question 2: Write a function which is passed an integer n and returns alist of n lists.
Example:
f(0) returns []
f(1) returns [[1]]
f(2) returns [[1], [1,2]]
f(3) returns [[1], [1,2], [1,3,2]]
'''
def list_generator(n):
	'''List generator function generator square bracket character along with the integers

	Args:
		n (int): Positive integer indicate the number of list and integer enclosed

	Returns:
		List[Lists]: Return List of multiple lists
	'''
	arr = []
	[arr.append(list(range(1, i+2))) for i in range(0,n)]

	return arr


if __name__ == "__main__":
	print("Generator for sum of all positive integer less than 102030 divisible by 3: ")
	print(generator(102030, 3))

	print("List generator")
	num1 = int(input("Enter a number of type int: "))
	print(list_generator(num1))
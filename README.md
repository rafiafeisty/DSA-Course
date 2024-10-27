<h1>DSA Tasks Code</h1>

### `DSALab1.cpp`
<p>In this file there is a simple function that inserts the value at the starting index of the array. This function works in a manner
  <ul>
    <li>It firsts check whether the 0 index is avaliable it then stores the value there.</li>
    <li>If not then it checks if there is any avaliable index. If there is no index avaliable then it gives the message of "fully packed array" message</li>
    <li>If an index is avaliable then it shifts the values to the next indexes and stores the value entered by user in the 0 index</li>
  </ul>
  The user can also remove, update,and search a value.
</p>

### `DSA_Lab2.cpp`
<p>In this file there are simple functions of linked list in which one can insert, delete, and find a function.
  <ul>
    <li><strong>InsertAtHead</strong> This functions allows the node to be entered at the beginning of the list</li>
    <li><strong>insertAtLast</strong> This functions allows the node to be inserted at the list at the end</li>
    <li><strong>update</strong> This function takes an index and value and update the value at that index in the list</li>
    <li><strong>searching</strong> This function takes a value and displays the value and index if the value exists else return an error</li>
    <li><strong>insertAfterIndex</strong> This function takes the value and index and insert that node after the index given by the user in the list</li>
    <li><strong>deleted</strong> This function takes a value find the value and delete that node from the list and if that values doesnt exist then gives the error message.</li>
    <li><strong>sorting</strong> This function sort the list in the ascending order</li>
  </ul>
</p>

### `DSA_Lab3.cpp`
<p>In this file there are functions that deals with the doubly linked list.</p>
<ul>
  <li><strong>InsertAtStart</strong> This function allows to insert the values at the start of the list</li>
  <li><strong>delete(int val)</strong> This function allows to delete the value by giving the specific value and then searching it in the list if value is found then it deletes it</li>
  <li><strong>RverseDisplay</strong> This function displays the whole list in the reverse order</li>
  <li><strong>insertAfterSpecificNode(int index, int val)</strong> This function allows to insert the value after the specific index given by the user</li>
  <li><strong>totalNodesCount</strong This function displays the total nodes in the list></li>
  <li><strong>MergeList(List *L1, List* L2)</strong> This function merge the two lists in the intersection manner</li>
  <li><strong>traverseList</strong> This function displays the list from the start to the end and from the end to the start</li>
</ul>

### `DSA_LabQuiz1.cpp`
<p>In this file there are some simple display and insert tasks of both single and double lists. There are 2 main functions here that are pairSum and partioning</p>
<ul>
<li><strong>pairSum</strong> This function takes a hardcode number and then iterate through the list and tak two numbers from the list in the form of the pair whose sum is equal to the given number</li>
<li><strong>Partioning</strong> This function takes a hardcode number and sort th list according to the 3 orders that is the numbers less then the given number, numbers equal to the given number and the numbers greater then the given number. This function then returns the node of the temporary list that stores the number is the order and then returns the head node of that list</li>
</ul>

### `DSA_Lab4.cpp`
<p>This file contains the functions that deals with the stack. There are stack functions for both the array and the list</p>
<ul>
  <li><strong>Stack </strong>class deals with the stack through the array. It contains the function <strong>Pop, Push, isEmpty, and isFull, display</strong> they are used to insert, and take out the values from the stack they also check whether the stack is empty or is full</li>
  <li><strong>List </strong>class deals with the stack through the list. It contains the function <strong>Pop, Push, isEmpty, and display</strong> they are used to insert, and take out the values from the stack they also check whether the stack is empty</li>
  <li><strong>isBalanced </strong>This function takes a string then converts it to the characters and store them in the stack after that checks the sequence of the brackets that are being entered by the user</li>
</ul>

### `DSA_Lab5.cpp`
<p>This file contains the code related to the <strong>Queue. </strong>There is an implementation of the Queue using both the array and the list</p>
<ul>
  <li><strong>Array-Based Queue: </strong>The array based queue is haing the functions used for enque, deque, display, isfull and isempty</li>
  <li><strong>List-Based Queue: </strong>The list based queue also performs the same functions enque, deque, display, isempty</li>
  <li><strong>Priority-Based Queue: </strong>In this Queue the lowest value node has the highest precedence. And the deque function is working according to that</li>
</ul>

### `(Quiz2).cpp`
<p>In this file there is some problem solved related to the stack and the queue</p>

/*
Source: https://www.codewars.com/kata/55befc42bfe4d13ab1000007/train/javascript
Diff: 7 Kyu

Linked Lists - Get Nth
Implement a GetNth() function that takes a linked list and an integer index and returns the node stored at the Nth index position. 
GetNth() uses the C numbering convention that the first node is index 0, the second is index 1, ... and so on.

So for the list 42 -> 13 -> 666, GetNth(1) should return Node(13);

getNth(1 -> 2 -> 3 -> null, 0).data === 1
getNth(1 -> 2 -> 3 -> null, 1).data === 2
The index should be in the range [0..length-1]. If it is not, or if the list is empty, GetNth() should throw/raise an exception 
(ArgumentException in C#, InvalidArgumentException in PHP, Exception in Java).
*/


function Node(data) {
    this.data = data;
    this.next = null;
}

function getNth(node, index) {
    while (index > 0 && node != null) {
        node = node.next;
        index--;
    }

    if (node == null || index < 0) throw Error();
    return node;
}

function push(head, data) {
    if (head == null) return new Node(data);
    let newNode = new Node(data);
    newNode.next = head;
    return newNode;
}

const assert = require('assert');

let head = null;
head = push(head, 1); 
head = push(head, 2); 
head = push(head, 3); 

assert.strictEqual(getNth(head, 0).data, 3);
assert.strictEqual(getNth(head, 1).data, 2);
assert.strictEqual(getNth(head, 2).data, 1);

assert.throws(() => getNth(head, 100), Error);
assert.throws(() => getNth(head, -1), Error);
assert.throws(() => getNth(null, 0), Error);

console.log('All tests passed');
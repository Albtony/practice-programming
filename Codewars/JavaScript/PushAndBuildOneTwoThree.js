/*
Source: https://www.codewars.com/kata/55be95786abade3c71000079/train/javascript
Diff: 7 Kyu

Linked Lists - Push & BuildOneTwoThree

Write push() and buildOneTwoThree() functions to easily update and initialize linked lists. Try to use the push() function within your buildOneTwoThree() function.

Here's an example of push() usage:

var chained = null
chained = push(chained, 3)
chained = push(chained, 2)
chained = push(chained, 1)
push(chained, 8) === 8 -> 1 -> 2 -> 3 -> null
The push function accepts head and data parameters, where head is either a node object or null/None/nil. Your push implementation should be able to 
create a new linked list/node when head is null/None/nil.

The buildOneTwoThree function should create and return a linked list with three nodes: 1 -> 2 -> 3 -> null
*/

function Node(data) {
    this.data = data;
    this.next = null;
}

function push(head, data) {
    if (head == null) return new Node(data);
    let newNode = new Node(data);
    newNode.next = head;
    return newNode;
}

function buildOneTwoThree() {
    return push(push(push(null, 3), 2), 1) 
}

const assert = require('assert');

assert.strictEqual(push(null, 1).data, 1);
assert.strictEqual(push(null, 1).next, null);
assert.strictEqual(push(new Node(1), 2).data, 2);
assert.strictEqual(push(new Node(1), 2).next.data, 1);

assert.strictEqual(buildOneTwoThree().data, 1);
assert.strictEqual(buildOneTwoThree().next.data, 2);
assert.strictEqual(buildOneTwoThree().next.next.data, 3);
assert.strictEqual(buildOneTwoThree().next.next.next, null);

console.log('All tests passed');
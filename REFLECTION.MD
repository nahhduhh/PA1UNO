1. Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?

Concat only needs to work between two lists of the same implementation because it reindexes the structures
that are already there. Trying to link a linkedlist and arraylist together would be difficult because an ArrayList
uses memory blocks that have indexes, but LinkedLists are nodes that have pointers. You'd have to make an entirely new
algorithm (that takes longer and increases space complexity) because you'd have to copy all the elements into a new
array.


2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

The pointers I'd need alive are previous, current, and next. Losing track of them makes a memory leak happen, because if you
wanted to make currents pointer point in the opposite direction before saving the places of current, previous, and next, all the upcoming players would lose their addresses and memory would get leaked.
You have to use the next pointer to "save" the rest of the turn order before doing anything.


3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

For addAnywhere, the range is 0 - size_. If size is 4, there were items in positions 0-3, you could add at 4 because it would
add them to the end of that array. For deleteAnywhere, the range is 0 - size-1, and for the same idea, you couldn't delete at 4 because
no item is there to delete in the first place. My implementation prints an error message if someone tries to use a position out of these ranges.


4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

We needed to walk to the end of the list because we didn't have a tail pointer to access the last node immediately. We have to walk node by node
until we hit a null pointer. addFront and DeleteFront never needs to walk node by node because it just accesses the first node of the list. If we did have
a tail_ pointer, concat would be o(1) instead of o(n) because of this. However, methods that would need to access the tail pointer would need a bit more code
to update that tail pointer so it doesn't point to a node that got deleted already.




5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

For addAnywhere, the "chair" that you want to insert into should be empty, and the people at the left of it get pulled into it. If you started at position and moved
the person at position into the chair into their right, they would sit on the person already there before they could get the chance to get up, effectively
overwriting them.


6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.

Line 45 is what physically flips the order. If the turn order is Wardell -> Deacon Blues -> Obama, the reverse would make it so that
the turn order would flip to Obama -> Deacon Blues -> Wardell. If the call were missing, reversing would do nothing and it would just be a glorified regular card lol.
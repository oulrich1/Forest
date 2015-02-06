#Red Black Tree
--------------

##Properties:
(0) Root is black
	[ Violated due to fixing violations over 1 and 2 ]

(1) Red nodes can only have black children
	[ Violated due to insertions or deletions ]
	
(2) Every path from any node to any decendant leaf 
	contains the same number of black nodes (aka black height)
	[ Violated due to insertions or deletions ]
    

##Goal:
Gaurentees O(log(n)) by following the properties
since the height is constrained by the number of 
black children per path from any node and that
each red node can only have black children...
  

#Insert, Delete, Find
--------------
(1) Must obey the properties
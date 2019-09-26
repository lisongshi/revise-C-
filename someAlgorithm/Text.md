1.hashmap
![Image text](https://github.com/lisongshi/reviseC-/blob/master/someAlgorithm/img/hashmap.png)

可以视为一种数组+链表的复合结构
1.具有不同hash index值的元素放在不同的bucket中，不同的bucket构成了一个数组。
2.具有相同hash index值的不同元素，则置于同一个bucket中，以链表的形式相连，若一个bucket中元素个数超限，则将链表转化为树。


由于数组与链表优势不一致。
数组：存储区间连续，需要一大块连续内存，但不产生额外内存需求。寻址容易，插入删除困难；
链表：存储区间离散，占用内存比较宽松，但会产生额外内存需求。寻址困难，插入删除容易；
hashmap优势：寻址与插入删除速度均较快。显然通过下标访问数组值时间复杂度为O(1)，而遍历链表时间复杂度O(n)，因此访问元素的时间不会超过O(n),若能限制链表长度n尽量小，则时间复杂度接近O(1)。插入删除与链表一致。

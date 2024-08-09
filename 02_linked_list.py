class Node:
    def __init__(self, v):
        self.val = v
        self.next = None


class linkedList:
    def __init__(self):
        self.head = None
        self.length = 0

    def printList(self):
        temp = self.head
        print("list:", "[" + str(self.length) + "] -", end="\t")
        while temp:
            print(temp.val, end=",")
            temp = temp.next
        print("\n")
        return

    def insertion(self, v, pos):
        newNode = Node(v)
        self.length += 1

        # empty
        if self.head is None:
            self.head = newNode
            # self.printList()

            return
        # head
        if pos == 1:
            newNode.next = self.head
            self.head = newNode
            # self.printList()

            return

        # MIDDLE
        current = self.head
        for i in range(2, pos):
            current = current.next
        # print(f"Current:{current.val}")
        newNode.next = current.next
        current.next = newNode
        # self.printList()
        return

    # def append(self, v):
    #     newNode = Node(v)
    #     self.length += 1

    #     # empty
    #     if self.head is None:
    #         self.head = newNode
    #         self.printList()

    #         return
    #     # head
    #     if pos == 1:
    #         newNode.next = self.head
    #         self.head = newNode
    #         self.printList()

    #         return

    #     # MIDDLE
    #     current = self.head
    #     for i in range(2, pos):
    #         current = current.next
    #     # print(f"Current:{current.val}")
    #     newNode.next = current.next
    #     current.next = newNode
    #     self.printList()
    #     return

    def deletion(self, pos):
        if self.head is None:
            print("Invalid Operation")
            return

        self.length -= 1
        if pos == 1:
            temp = self.head
            self.head = self.head.next
            del temp
            print("deleted")
            return
        # mid
        current = self.head
        for i in range(2, pos):
            current = current.next
        # print("Current:", current.val)
        temp = current.next
        current.next = current.next.next
        del temp
        print("deleted")

        return

    def middle(self):
        if self.head is None:
            print("Invalid Operation")
            return
        slowP = self.head
        fastP = self.head

        while fastP and fastP.next:
            slowP = slowP.next

            fastP = fastP.next.next

        print("MIDDLE: ", slowP.val, end="\n\n\n")

        return

    def cycle(self):
        if self.head is None:
            print("Invalid Operation")
            return
        slowP = self.head
        fastP = self.head

        while fastP and fastP.next:
            print("S", slowP.val)
            print("F", fastP.val)
            slowP = slowP.next
            fastP = fastP.next.next

            if slowP == fastP:
                print("didit")
                return True

        return False

    """
        Floyd's cycle-finding algorithm is a pointer algorithm that uses only two pointers,
        which move through the sequence at different speeds. 
        It is also called the "tortoise and the hare algorithm".
    """

    def reverse(self):
        current = self.head
        prev = None
        print("*")
        self.printList()
        while current:
            forward = current.next
            current.next = prev
            prev = current
            current = forward
        self.head = prev
        print("*")
        self.printList()
        return self.head

    def deletenth1(self, nth):
        print("*****************************88")
        self.printList()
        pos = self.length - nth

        print("POS:", pos)
        self.deletion(pos)
        self.printList()

    def deletenth(self, nth):
        if nth == self.length:
            dummy = self.head
            self.head = self.head.next
            del dummy
            self.printList()

            return

        if not self.head:
            return self.head.next

        slow, fast = self.head, self.head

        for i in range(nth):
            fast = fast.next

        print("SLOW:", slow.val, "Fast:", fast.val)

        while fast.next:
            slow = slow.next
            fast = fast.next
        print("SLOW:", slow.val, "Fast:", fast.val)

        dummy = slow.next
        slow.next = slow.next.next
        del dummy

        self.printList()

    def palindromew(self):
        self.printList()
        fast, slow = self.head, self.head
        while fast and fast.next:
            slow = slow.next

            fast = fast.next.next

        if fast:
            slow = slow.next
        print("SLOW:", slow.val)

        # Reverse
        current = slow
        prev = None
        # slow = slow.next
        # prev.next = None

        while current:
            forward = current.next
            # current.next = prev
            # prev = current
            # current = forward
            print("Current: ", current.val)

            # print("Prev: ", prev.val)
            current.next = prev
            prev = current
            current = forward
            # self.printList()

        print("Prev: ", prev.val)
        print("P", end="\t")

        while prev:
            print(prev.val, end="---")
            prev = prev.next
        print()
        fast = self.head
        print(slow.val)
        # slow = prev
        print(slow.val)

        print("F", end="\t")
        while fast:
            print(fast.val, end="---")
            fast = fast.next

    def palindromes(self):
        fast = self.head
        slow = self.head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # print(fast.val, "|")
        print("S", slow.val, "|")

        # Reverse
        current = slow
        prev = None
        while current:
            forward = current.next
            current.next = prev
            prev = current
            current = forward

        # print("Reversed: ")
        # temp = prev
        # while temp:
        #     print(temp.val, end=",,")
        #     temp = temp.next
        # fast = self.head
        # print()
        # print("Straight: ")

        # while fast:
        #     print(fast.val, end=",,")
        #     fast = fast.next

        print()
        print("S", slow.val, end=",,")
        print()
        fast = self.head
        while fast and prev:
            print("P", prev.val, "F", fast.val)
            if prev.val != fast.val:
                print("Not")

                return False
            prev = prev.next
            fast = fast.next
        return True
        # self.printList()

    def palindrome(self):
        self.printList()

        slow = self.head
        fast = self.head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        print("Mid:", slow.val)

        # reverse

        prev = None
        current = slow
        while current:
            print(current.val, end=" | ")
            forward = current.next
            current.next = prev
            prev = current
            current = forward
        print()
        print("reversed")
        slow = prev
        while slow:
            print(slow.val, end=" | ")
            slow = slow.next
        print()
        print("Palindrome?")
        slow = prev
        fast = self.head

        while slow:
            if fast.val != slow.val:
                print(False)
                return False
            print(fast.val, ":", slow.val, end=" | ")

            fast = fast.next
            slow = slow.next
        print(True)
        return True

    def palindromeA(self):
        self.printList()
        #
        fast = slow = self.head
        # print(fast.val, ":", slow.val)

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # print(slow.val)
        prev = None
        current = slow
        while current:
            # print(current.val, end=",")
            # current = current.next

            forward = current.next
            current.next = prev
            prev = current
            current = forward
        reversed = prev
        print("reversed:")
        while reversed:
            print(reversed.val, end=",")
            reversed = reversed.next

        point1 = self.head
        point2 = prev
        print()
        while point2:
            print(point1.val, ":", point2.val, end="||")
            if point1.val != point2.val:
                print(":NOOOT PALINDROME")
                return False
            point2 = point2.next
            point1 = point1.next
        print(": PALINDROME")

        return True

    def palindrome(self):
        self.printList()

        fast, slow = self.head, self.head
        # finding middle
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        print(f"middle:{slow.val}")

        # reversing
        prev = None
        current = slow

        while current:
            forward = current.next

            current.next = prev
            prev = current
            current = forward

        reversed = prev
        while reversed:
            print(reversed.val, end=" ")
            reversed = reversed.next

        # palindrome
        point1 = self.head
        point2 = prev

        while point2:
            if point1.val != point2.val:
                print(" \nnot P")
                return False
            point1 = point1.next
            point2 = point2.next
        print("\nP")
        return True

    def swappairss(self):
        self.printList()
        dummy = Node(999)
        dummy.next = self.head
        point = dummy

        # while swap2 and swap2.next:
        while point.next and point.next.next:  # ensure nodes being swapped are not null
            swap1 = point.next
            swap2 = point.next.next
            # print(swap1.val, ":", swap2.val, ", ", end=" -> ")
            # print()
            # swap
            swap1.next = swap2.next
            swap2.next = swap1
            # prepare for next
            point.next = swap2
            point = swap1

            # print(swap1.val, ":", swap2.val, ", ", end=" -> ")

        self.head = dummy.next
        self.printList()

    def swappairs(self):
        self.printList()

        dummy = Node(99)
        dummy.next = self.head
        point = dummy

        while point.next and point.next.next:
            swap1 = point.next
            swap2 = point.next.next
            # actual swap
            swap1.next = swap2.next
            swap2.next = swap1
            point.next = swap2
            point = swap1

        self.head = dummy.next
        self.printList()

    def swappairs(self):
        self.printList()

        dummy = Node(999)
        dummy.next = self.head

        point = dummy

        while point.next and point.next.next:
            swap1 = point.next
            swap2 = point.next.next
            swap1.next = swap2.next
            swap2.next = swap1
            point.next = swap2
            point = swap1
            # print(point.val, end="\t")

        self.head = dummy.next
        self.printList()

    # def swappairs(self):
    #     self.printList()

    #     dummy = Node(12)

    #     dummy.next = self.head

    #     point = dummy

    #     while point.next and point.next.next:
    #         swap1 = point.next
    #         swap2 = point.next.next

    #         swap1.next = swap2.next
    #         swap2.next = swap1
    #         point.next = swap2
    #         point = swap1

    #     self.head = dummy.next
    #     print("Swapped")
    #     self.printList()

    # def swappairs(self):
    #     dummy = Node(45)
    #     dummy.next = self.head
    #     point = dummy

    #     while point.next and point.next.next:
    #         swap1 = point.next
    #         swap2 = point.next.next

    #         swap1.next = swap2.next
    #         swap2.next = swap1
    #         point.next = swap2
    #         point = swap1
    #     self.head = dummy.next
    #     self.printList()

    def oddEven(self):
        self.printList()
        odd, even = self.head, self.head.next
        o, e = odd, even
        # pointerOne = odd

        while even and even.next:
            # pointerOne.next = odd  # odd
            # print("O", odd.val, end=",")

            # print("E", even.val, end=",")
            odd.next = odd.next.next
            odd = odd.next
            even.next = even.next.next
            even = even.next
            # pointerOne = pointerOne.next

        odd.next = e
        # even.next = o
        self.head = o

        # print("\nO:")

        # while o:
        #     print(o.val, end=" - ")
        #     o = o.next
        # print("\nE:")
        # while e:
        #     print(e.val, end="--")
        #     e = e.next

        self.printList()

    # ############################################################################

    def oddEven(self):
        if not self.head or not self.head.next:
            return self.head
        odd, even = self.head, self.head.next
        evenHead = even

        while even and even.next:
            odd.next = odd.next.next
            odd = odd.next
            even.next = even.next.next
            even = even.next

        odd.next = evenHead
        self.printList()
        return self.head

    def oddEven(self):
        self.printList()

        if not self.head and not self.head.next:
            return self.head

        odd, even = self.head, self.head.next
        evenHead = even

        while even and even.next:
            odd.next = odd.next.next
            odd = odd.next

            even.next = even.next.next
            even = even.next
        odd.next = evenHead

        self.printList()
        return


###################################################################################################################################33


def mergeSorted(l1, l2):
    print("listOne:", end="\t")
    l1.printList()
    print("listtwo:", end="\t")
    l2.printList()
    h1, h2 = l1.head, l2.head
    c1, c2 = h1, h2

    if not h2 and not h1:
        print("Nothing")
        return
    if not h1:
        print("#2")
        l2.printList()
        return l2
    if not h2:
        print("#1")
        l1.printList()
        return l1

    curr = result = linkedList()

    while c1 and c2:
        if c1.val < c2.val:
            curr.next = c1
            c1 = c1.next
        else:
            curr.next = c2
            c2 = c2.next
        curr = curr.next

    curr.next = c1 or c2

    result.head = result.next
    print("***********************")
    result.printList()

    print("***********************")
    return result.next


def addTwoNumbers(linkedO, linkedS):
    linkedO.printList()
    linkedS.printList()
    l1, l2 = linkedO.head, linkedS.head

    result = Node(0)
    ptr = result
    carry = 0

    while l1 or l2 or carry:
        sum = 0 + carry

        # print("First:", end="\t")
        if l1:
            print(l1.val, end="")
            sum += l1.val
            l1 = l1.next
        # print()
        # print("Second:", end="\t")

        if l2:
            print(" + ", l2.val, end="")
            sum += l2.val
            l2 = l2.next

        carry = int(sum / 10)
        sum = sum % 10
        print(" =", sum, "    |||     S:", sum, "C:", carry)

        ptr.next = Node(sum)
        ptr = ptr.next

    return result.next


def addTwoNumbers(linkedO, linkedS):
    linkedO.printList()
    linkedS.printList()
    l1, l2 = linkedO.head, linkedS.head
    # print("l1:", l1.val, "l2:", l2.val)

    l3 = h3 = Node(0)

    carry = 0

    while l1 or l2 or carry:
        sum = carry
        if l1:
            # print(l1.val, end=" ")
            sum += l1.val
            l1 = l1.next

        if l2:
            # print("+", l2.val, end="")
            sum += l2.val
            l2 = l2.next

        carry = int(sum / 10)
        sum = sum % 10
        l3.next = Node(sum)
        l3 = l3.next
        print(sum, end="\t")

    return h3.next


def 


if __name__ == "__main__":
    l = linkedList()
    # l.deletion(2)
    # l.insertion(2, 1)
    # l.insertion(1, 1)
    # l.insertion(3, 3)
    # l.insertion(5, 4)
    # l.insertion(4, 4)
    # l.middle()
    # l.insertion(14, 6)
    # print(l.cycle())

    # v = Node(1)
    # print(v == Node(1))
    # l.deletion(5)
    # l.printList()

    l1 = linkedList()
    l2 = linkedList()
    # l.head = Node(10)
    # l.head.next = Node(20)
    l1.insertion(1, 1)
    l1.insertion(2, 2)
    l1.insertion(3, 3)
    l1.insertion(4, 4)
    l1.insertion(5, 5)
    l1.insertion(6, 6)
    l1.insertion(5, 7)
    l1.insertion(4, 8)
    l1.insertion(3, 9)
    l1.insertion(2, 10)

    l1.insertion(11, 11)

    # l1.insertion(12, 12)
    # print("Insertion completed")
    # l2.insertion(2, 1)
    # l2.insertion(4, 2)
    # l2.insertion(7, 3)
    # l1.printList()
    # l1.reverse()
    # mergeSorted(l1, l2)
    # print(l1.length)
    # l1.middle()
    l1.palindrome()
    # l1.swappairs()
    # l1.oddEven()
    # linkedO = linkedList()
    # linkedS = linkedList()
    # linkedO.insertion(9, 1)
    # linkedO.insertion(9, 2)
    # linkedO.insertion(9, 3)
    # linkedO.insertion(9, 4)

    # // 987 + 13
    # 7 => 8 => 9
    # linkedS.insertion(4, 1)
    # linkedS.insertion(6, 2)

    # linkedS.insertion(4, 3)
    # 3 => 1

    # + = 1000

    # linkedO.printList()
    # linkedS.printList()
    # x = addTwoNumbers(linkedO, linkedS)
    # print("nice")
    # while x:
    #     print(x.val, end=" -> ")
    #     x = x.next

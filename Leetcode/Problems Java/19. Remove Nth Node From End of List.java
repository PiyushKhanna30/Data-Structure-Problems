/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode tempHead = new ListNode();
        tempHead.next = head;
        ListNode slow = tempHead, fast = tempHead;
        for (int i = 1; i <= n; i++)
            fast = fast.next;
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return tempHead.next;
    }

//    public ListNode removeNthFromEnd(ListNode head, int n) {
//        ListNode temp = new ListNode();
//        temp.next = head;
//        int sz = sizeOfLL(temp.next);
//        int indexFromBeg = sz - n;
//        ListNode t = temp;
//        for (int i = 1; i <= indexFromBeg; i++) {
//            t = t.next;
//        }
//        t.next = t.next.next;
//        return temp.next;
//    }
//
//    private int sizeOfLL(ListNode head) {
//        ListNode t = head;
//        int sz = 0;
//        while (t != null) {
//            t = t.next;
//            sz += 1;
//        }
//
//        return sz;
//    }
}

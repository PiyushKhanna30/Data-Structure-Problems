/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    //m1 store in array then create new and return(iter+rec).
    public ListNode reverseListRec(ListNode head) {
        if(head==null || head.next == null)return head;
        ListNode res = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return res;
    }
    public ListNode reverseList(ListNode head) {
        ListNode prev=null;
        ListNode curr=head;
        ListNode nex=head;
        while(curr!=null){
            nex = nex.next;
            curr.next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
}

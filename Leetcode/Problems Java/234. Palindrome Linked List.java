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
    private ListNode midOfLL(ListNode head){
        if(head==null || head.next == null)return head;
        ListNode slow = head;
        ListNode fast = head;
        ListNode prevSlow = null;
        while(fast!=null && fast.next!=null){
            prevSlow = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        return prevSlow;
    }
    private ListNode reverse(ListNode head){
        ListNode next = null;
        ListNode curr = head;
        ListNode prev = null;
        while(curr!=null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    private boolean compareLl(ListNode ll1, ListNode ll2){
        while(ll1!=null && ll2!=null){
            if(ll1.val != ll2.val)return false;
            ll1 = ll1.next;
            ll2 = ll2.next;
        }
        return true;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode mid  = midOfLL(head);
        ListNode ll1 = head;
        ListNode ll2 = mid.next;
        mid.next = null;
        
        ll2 = reverse(ll2);
        
        boolean result = compareLl(ll1, ll2);
        
        ll2 = reverse(ll2);
        mid.next = ll2;
        
        return result;
    }
}

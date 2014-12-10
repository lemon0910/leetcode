/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(NULL == head)
    		return NULL;
        map<RandomListNode*, int> m_first;
        map<int, RandomListNode*> m_second;

        RandomListNode *p = head;
        int k = 1;
        while(p)
        {
        	m_first[p] = k++;
        	p = p->next; 
        }

        RandomListNode temp(0);
        RandomListNode *q = &temp;
        p = head;
        k = 1;
        while(p)
        {
        	RandomListNode *r = new RandomListNode(p->label);
        	r->random = p->random;
        	m_second[k++] = r;
        	q->next = r;
        	q = q->next;
        	p = p->next;
        }

        q = (&temp)->next;
        while(q)
        {
        	if(q->random)
        		q->random = m_second[m_first[q->random]];

        	q = q-> next;
        }

        return temp.next;
    }
};
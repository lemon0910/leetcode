class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (NULL == head)
			return head;

		int len = 0;
		ListNode *temp = head;
		while (temp)
		{
			len++;
			temp = temp->next;
		}

		k %= len;
		if (k == 0)
			return head;
		int step = len - k;
		temp = head;
		ListNode *prev = NULL;

		while (temp)
		{
			if (temp->next == NULL)
			{
				temp->next = head;
				break;
			}

			temp = temp->next;
		}

		temp = head;
		while (step--)
		{
			prev = temp;
			temp = temp->next;
		}

		prev->next = NULL;
		head = temp;
		return head;
	}
};
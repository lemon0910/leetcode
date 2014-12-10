class MinStack {
public:
    void push(int x) {
        value.push(x);
        if(minV.empty())
            minV.push(node(x, 0));
        else
        {
            if(minV.top().value <= x)
                minV.top().pos++;
            else
                minV.push(node(x, minV.top().pos + 1));
        }
    }

    void pop() {
        value.pop();
        node temp = minV.top();
        minV.pop();
        if(minV.empty())
        {
            if(temp.pos == 0)
                return;
            else
            {
                temp.pos--;
                minV.push(temp);
            }
        }
        if(temp.pos - minV.top().pos > 1)
        {
            temp.pos--;
            minV.push(temp);
        }
    }

    int top() {
        return value.top();
    }

    int getMin() {
        return minV.top().value;
    }
    
private:
    struct node
    {
        int value;
        int pos;
        
        node(int x, int position)
        {
            value = x;
            pos = position;
        }
    };
    stack<int> value;
    stack<node> minV;
};

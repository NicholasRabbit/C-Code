

char stack[512];
int top = -1;

void push(char c)
{
	stack[++top] = c;
}

char pop()
{
	return stack[top--];
}

int is_empty()
{
	return top == -1;
}

// This function can only be used here.
static int list(int i)
{
	return 0;
}

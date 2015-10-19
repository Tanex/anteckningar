int execute(struct TreeNode *root)
{
	if (root == NULL)
		;
	else if (root->type == TAL)
		return root->leaf_value;
	else if (root->type == ID)
		return symtable[root->leaf_value].value;
	else if (root->type == PLUS)
	{
		int arg1 = execute(root->args[0]);
		int arg2 = execute(root->args[1]);
		return arg1 + arg2;
	}
	else if (root->type == IF)
	{
		int villkor = execute(root->args[0]);
		if (villkor)
			execute(root->args[1]);
		else
			execute(root->args[2]);
	}
	else ...
}

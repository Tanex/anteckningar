#define MAXARGS 4

enum NodeType { IF, WHILE, PLUS, MINUS, ... };

struct TreeNode
{
	enum NodeType type;
	struct TreeNode *args[MAXARGS];
	int leaf_value;
};

//mknode(op, left, right)
//mkleaf(NUM, 3)
//mkleaf(ID, 17)
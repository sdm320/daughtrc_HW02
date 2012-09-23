class Node {
public:
	Node* next_;
	int x;
	int y;
	int length;
	float r;
	float g;
	float b;

	Node(int x_coord, int y_coord, int length, float red, float green, float blue);
	~Node(void);
};
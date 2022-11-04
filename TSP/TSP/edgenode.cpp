#include"edgenode.h"

edgenode::edgenode() {
	weight = vertex = vis = 0;
}


edgenode::edgenode(int _weigth, int _vertex) {
	weight = _weigth;
	vertex = _vertex;
	vis = 0;
}
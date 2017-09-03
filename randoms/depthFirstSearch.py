class Graph:
	def __init__(self, _V):
		self.V = _V
		self.adjMat = [[None] for i in range(self.V)]
	
	def addEdge(self, x, y):
		self.adjMat[x][y] = self.adjMat[y][x] = 1

	def depthFirstSarch(self, src):
		visited, stack = set(), [src]
		while stack:
			src = stack.pop()
			vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
    	return visited

    


#!usr/bin/python3
from collections import defaultdict
"""
class Graph:
	adjList = {}
	def __init__(self, gdict = None):
		if gdict == None:
			gdict = {}
		self.adjList = gdict
	def getVertices(self):
		return list(adjList.keys())
	def getEdges(self):
		return slef.generateEdges()
	def generateEdges(self):
		edges = []
		for source in self.adjList:
			for destination in self.adjList[source]:
				if {source, destination} not in edges:
					edges.append({source, destination})
		return edges
	def addEdge(self, edge):
		edge = set(edge)
		(vertexA, vertexB) = tuple(edge)
		if vertexA in self.adjList:
			self.adjList[vertexA].append(vertexB)
		else:
			self.adjList[vertexA] = [vertexB]
	def addVertex(self, vertex):
		if vertex not in self.adjList:
			adjList[vertex] = []
	
"""
class Queue:
	def __init__(self):
		self.A = []
	def enqueue(self, x):
		self.A.insert(0, x)
	def dequeue(self):
		if not self.isEmpty():
			self.A.pop()
		else :
			print("*****QUEUE UNDERFLOW*****")
	def size(self):
		return len(self.A)
	def front(self):
		if not self.isEmpty():
			return self.A[-1]
		else :
			print("*****QUEUE UNDERFLOW*****")
	def isEmpty(self):
		return self.A == []

class Stack(object):
	def __init__(self):
		self.A = []
	def push(self, x):
		self.A.append(x)
	def isEmpty(self):
		return self.A == []
	def pop(self):
		if not self.isEmpty():
			self.A.pop()
		else:
			print("*****STACK UNDERFLOW ERROR.*****")
	def top(self):
		if not self.isEmpty():
			return self.A[-1]
		else :
			print("*****STACK UNDERFLOW ERROR.*****")
	def size(self):
		return len(self.A)

class Graph(object):
	"""docstring for Graph"""
	def __init__(self, V):
		self.numOfVertices = V
		self.adjList = defaultdict(list)		
	def addEdge(self, source, destination):
		self.adjList[source].append(destination)
	def sizeOfGraph(self):
		return  self.numOfVertices
	def getNumberOfEdges(self):
		return len(self.adjList)
	def depthFirstSearch(self, source):
		S = Stack()
		S.push(source)
		visited = [False] * self.sizeOfGraph()
		#print(visited)
		traversedNodes = []
		while not S.isEmpty():
			k = S.top()
			S.pop()
			traversedNodes.append(k)
			if not visited[k]:
				visited[k] = True
				for j in self.adjList[k]:
					if not visited[j]:
						S.push(j)
		return traversedNodes
	def breadthFirstSearch(self, source):
		Q = Queue()
		Q.enqueue(source)
		visited = [False] * self.sizeOfGraph()
		#print(visited)
		traversedNodes = []
		while not Q.isEmpty():
			k = Q.front()
			Q.dequeue()
			traversedNodes.append(k)
			if not visited[k]:
				visited[k] = True
				for j in self.adjList[k]:
					if not visited[j]:
						Q.enqueue(j)
		return traversedNodes

def main():
	V = int(input())
	G = Graph(V)
	E = int(input())
	for e in range(E):
		s, d = map(int, input().split())
		G.addEdge(s, d)
	#print(G.adjList)
	s = int(input())
	traversedVertices = G.depthFirstSearch(s)
	print("Depth first Search strting at {0} gives {1}".format(s, traversedVertices))
	traversedVertices = G.breadthFirstSearch(s)
	print("Breadth first Search strting at {0} gives {1}".format(s, traversedVertices))

if __name__ == '__main__':
	main()

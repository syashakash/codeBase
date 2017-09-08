#!usr/bin/python3
import numpy as np

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
	

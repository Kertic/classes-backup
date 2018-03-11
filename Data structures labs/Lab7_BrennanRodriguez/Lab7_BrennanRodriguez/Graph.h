#pragma once
#include "DynArray.h"
#include "SLList.h"

template <typename Type>
class Graph
{
public:
	struct Edge {
		unsigned int toVertex;
		Edge() {

		}
		Edge(int index) {
			toVertex = index;
		}


	};



	struct Vertex {


		// the data that this vertex is storing
		Type element;
		// the list of edges that connect this vertex to another vertex
		SLList<Edge> edges;
		Vertex() {

		}

		Vertex(Type value) {
			element = value;

		}

		///////////////////////////////////////////////////////////////////////////
		// Function : addEdge
		// Parameters : toVertex - the index of the vertex we are adjacent to
		///////////////////////////////////////////////////////////////////////////
		void addEdge(const unsigned int& toVertex) {
			edges.addHead(Edge(toVertex));
		}

		void clear() {
			edges.clear();
		}

	};

private:

	DynArray<Vertex> vertices;
public:



	Graph() {

	}
	~Graph() {
		clear();
	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : addVertex
	// Parameters : value - the data to store in this vertex
	// Return : unsigned int - the index this vertex was added at
	/////////////////////////////////////////////////////////////////////////////
	unsigned int addVertex(const Type& value) {
		unsigned int index = vertices.size();
		vertices.append(Vertex(value));

		return 0;

	}
	/////////////////////////////////////////////////////////////////////////////
	// Function : operator[]
	// Parameters : index - the index in the graph to access
	// Return : Vertex& - the vertex stored at the specified index
	/////////////////////////////////////////////////////////////////////////////
	Vertex& operator[](const unsigned int& index) {

		return vertices[index];

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : size
	// Return : unsiged int - the number of vertices in the graph
	/////////////////////////////////////////////////////////////////////////////
	unsigned int size() const {


		return vertices.size();
	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : clear
	// Notes : clears the graph and readies it for re-use
	/////////////////////////////////////////////////////////////////////////////
	void clear() {
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			vertices[i].clear();
		}
		vertices.clear();

	}





	//The structure for holding the layer and the vertex

	struct VertexAndLayer {
		Vertex* _vert;//A pointer to the vertex itself
		unsigned int _layer;//A number to represent what layer we are on
		VertexAndLayer() {

		}

		VertexAndLayer(Vertex* inVert, unsigned int inLayer) {
			_vert = inVert;
			_layer = inLayer;

		}

	};

	/////////////////////////////////////////////////////////////////////////////
	// Function : printBreadthFirst
	// Parameters : startVertex - the vertex to start the traversal at
	// Notes : prints contents of the graph in depth order 
	//			(from closest to farthest)
	/////////////////////////////////////////////////////////////////////////////
	void printBreadthFirst(const unsigned int& startVertex) {


		DynArray<Vertex*> temp;//This will store the memory addresses of the verticies
		DynArray<VertexAndLayer> queue; //This will store the memory addresses of the verticies and the layer we're on
		unsigned int layer = 0;
		enqueue(temp, queue, &vertices[startVertex], layer);
		while (queue.size() > 0)
		{


			VertexAndLayer tempVAL = dequeue(temp, queue, queue[0]._layer + 1);//The layer of the current is equal to the layer of the its predecessor +1
			cout << "\n" << tempVAL._vert->element << " : " << tempVAL._layer;

		}



		queue.clear();





	}



	/////////////////////////////////////////////////////////////////////////////
	// Function : enqueue
	// Parameters : inTemp - the array of the traversals history
	//				inQue - the current que of Vertexes (the struct is there to track the distance from the original vertex)
	//				inVert - The pointer to the vertex we will try to queue
	//				inLayer - the Layer that we're currently in, and will add to que if the vertex hasnt been used yet
	// Notes : Enques a vertex and its current layer if it hasnt been queued already. (For use in the bredth first traversal only)
	/////////////////////////////////////////////////////////////////////////////
	void enqueue(DynArray<Vertex*> &inTemp, DynArray<VertexAndLayer> &inQue, Vertex *inVert, unsigned int inLayer) {


		bool hasQueued = false;
		for (unsigned int i = 0; i < inTemp.size(); i++)
		{



			if (inTemp[i] == inVert)//If temp 
			{
				hasQueued = true;
			}
		}

		if (!hasQueued)
		{
			inTemp.append(inVert);
			VertexAndLayer tempV(inVert, inLayer);
			inQue.append(tempV);
		}

	}

	/////////////////////////////////////////////////////////////////////////////
	// Function : dequeue
	// Parameters : inTemp - the array of the traversals history
	//				inQue - the current que of Vertexes (the struct is there to track the distance from the original vertex)
	//				inLayer - the Layer that we will send to enqueue(), and is the layer we're current on.
	// Notes : Removes the first vertex inside of inQue, shifts the remaining items forward, and returns the structure containing the vertex pointer and its current layer (For use in the bredth first traversal only)
	/////////////////////////////////////////////////////////////////////////////
	VertexAndLayer dequeue(DynArray<Vertex*> &inTemp, DynArray<VertexAndLayer> &inQue, unsigned int inLayer) {

		SLLIter<Edge> iter(inQue[0]._vert->edges);

		for (unsigned int i = 0; i < inQue[0]._vert->edges.size(); i++)
		{
			enqueue(inTemp, inQue, &vertices[iter.current().toVertex], inLayer);
			++iter;
		}

		Vertex* vert = inQue[0]._vert;
		unsigned int layer = inQue[0]._layer;
		inQue.remove(0);
		VertexAndLayer temp(vert, layer);
		return temp;




	}


};


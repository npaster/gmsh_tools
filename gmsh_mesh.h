/*
 *       /\
 *      /__\       Nicolas Pignet (C) 2017
 *     /_\/_\      École Nationale des Ponts et Chaussées - CERMICS
 *    /\    /\
 *   /__\  /__\    Gmsh tools
 *  /_\/_\/_\/_\
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * If you use this code for scientific publications, you are required to
 * cite it.
 */

#include<vector>
#include<string>

class Node
{
    protected:
        std::vector<double> _coordinate;
        int _num;
        int _ref;
    public:
        Node();
        Node(std::vector<double> vert, int num, int ref);
        void print();
        std::vector<double> getCoordinate();
        int getRef();
        int getNum();
        void modifyNum(const int num);
        void modifyRef(const int ref);
};


class Element
{
   protected:
      std::vector<int> _nodes;
      int _num;
      int _type_elem;
      int _physical_entities;
      int _elem_tag;

   public:
      Element();
      Element(std::vector<int> nodes, int num, int type_elem, int physical_entities, int elem_tag );
      int getNum() const;
      int getTypeElem() const;
      int getPhysicalEntities() const;
      int getElemTag() const;
      std::vector<int> getNodes() const;
      void print() const;
};

class Edge
{
    private:
        std::vector<int> _nodes;
        int _ref;
        int _num;
    public:
        Edge();
        Edge(std::vector<int> nodes, int num, int ref);
        void print();
        int getRef();
        std::vector<int> getNodes();
        int getNum();
};

class Triangle
{
    private:
        std::vector<int> _nodes;
        int _ref;
        int _num;
    public:
        Triangle();
        Triangle(std::vector<int> nodes, int num, int ref);
        void print();
        std::vector<int> getNodes();
        int getRef();
        int getNum();
};

class Quadrangle
{
    private:
        std::vector<int> _nodes;
        int _ref;
        int _num;
    public:
        Quadrangle();
        Quadrangle(std::vector<int> nodes, int num, int ref);
        void print();
        std::vector<int> getNodes();
        int getRef();
        int getNum();
};

class Tetrahedron
{
   private:
      std::vector<int> _nodes;
      int _ref;
      int _num;
   public:
      Tetrahedron();
      Tetrahedron(std::vector<int> nodes, int num, int ref);
      void print();
      std::vector<int> getNodes();
      int getRef();
      int getNum();
};

class Hexahedron
{
   private:
      std::vector<int> _nodes;
      int _ref;
      int _num;
   public:
      Hexahedron();
      Hexahedron(std::vector<int> nodes, int num, int ref);
      void print();
      std::vector<int> getNodes();
      int getRef();
      int getNum();
};

class Prism
{
   private:
      std::vector<int> _nodes;
      int _ref;
      int _num;
   public:
      Prism();
      Prism(std::vector<int> nodes, int num, int ref);
      void print();
      std::vector<int> getNodes();
      int getRef();
      int getNum();
};

class Pyramid
{
   private:
      std::vector<int> _nodes;
      int _ref;
      int _num;
   public:
      Pyramid();
      Pyramid(std::vector<int> nodes, int num, int ref);
      void print();
      std::vector<int> getNodes();
      int getRef();
      int getNum();
};

class Gmesh
{
   protected:
     std::vector<Node> _nodes;
     std::vector<Edge> _edges;
     std::vector<Triangle> _triangles;
     std::vector<Quadrangle> _quadrangles;
     std::vector<Tetrahedron> _tetrahedra;
     std::vector<Hexahedron> _hexahedra;
     std::vector<Prism> _prisms;
     std::vector<Pyramid> _pyramids;
     int _number_of_elements;
     void readGmesh_MESHformat(const std::string name_mesh);
     void writeGmesh_MESHformat(const std::string name_mesh) const;
     void readGmesh_MSHformat(const std::string name_mesh);
     void writeGmesh_MSHformat(const std::string name_mesh) const;


   public:
     Gmesh();
     void readGmesh(const std::string name_mesh);
     void writeGmesh(const std::string name_mesh, const int format) const;
     void getInfo();
     int getNumberofNodes();
     int getNumberofElements();
     std::vector<Node> getNodes();
     std::vector<Edge> getEdges();
     std::vector<Triangle> getTriangles();
     std::vector<Quadrangle> getQuadrangles();
     std::vector<Hexahedron> getHexahedra();
     std::vector<Tetrahedron> getTetrahedra();
     std::vector<Prism> getPrisms();
     std::vector<Pyramid> getPyramids();

     void addNode(const Node& node);

};

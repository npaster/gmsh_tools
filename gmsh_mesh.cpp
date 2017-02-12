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


#include "gmsh_mesh.h"
#include<iostream>
#include<fstream>
#include <assert.h>



// Class Node

Node::Node() : _coordinate(), _num(0), _ref(0) {}


Node::Node(std::vector<double> vert, int num, int ref) :
                _coordinate(vert), _num(num), _ref(ref)
{
  assert((_coordinate.size() == 3) && "The size of the point is not equal to 3 !");
}

void Node::print()
{
   std::cout << "--------------- Node --------------"  << std::endl;
   std::cout << "Number: " << _num << std::endl;
   std::cout << "Reference: " << _ref << std::endl;
   std::cout << "Coordinates: "  << std::endl;
   std::cout << "[x, y, z] = [ " << _coordinate[0] << " "
                                 << _coordinate[1] << " "
                                 << _coordinate[2] << " ];" << std::endl;
   std::cout << "--------------------------------------" <<  std::endl;
}

std::vector<double> Node::getCoordinate()
{
  return _coordinate;
}

int Node::getRef()
{
    return _ref;
}

int Node::getNum()
{
    return _num;
}

void Node::modifyNum(const int num) {_num = num;}
void Node::modifyRef(const int ref) {_ref = ref;}

// Class Element
Element::Element() : _nodes(), _num(0), _type_elem(0),
                      _physical_entities(0), _elem_tag(0) {}

Element::Element(std::vector<int> nodes, int num, int type_elem, int physical_entities, int elem_tag )
               : _nodes(nodes), _num(num), _type_elem(type_elem),
                  _physical_entities(physical_entities), _elem_tag(elem_tag) {}


int Element::getNum() const
{
   return _num;
}

int Element::getTypeElem() const
{
   return _type_elem;
}

int Element::getPhysicalEntities() const
{
   return _physical_entities;
}

int Element::getElemTag() const
{
   return _elem_tag;
}

std::vector<int> Element::getNodes() const
{
   return _nodes;
}

void Element::print() const
{
   std::cout << "--------------- Element --------------"  << std::endl;
   std::cout << "Number: " << _num << std::endl;
   std::cout << "Type_elem: " << _type_elem << std::endl;
   std::cout << "Physical_entities: " << _physical_entities << std::endl;
   std::cout << "ElemTag: " << _elem_tag << std::endl;
   std::cout << "Number of Node: " << _nodes.size() << std::endl;

   for (size_t i = 0; i < _nodes.size(); i++) {
      std::cout << "Node " << i << " " << _nodes[i]  << std::endl;
   }

   std::cout << "--------------------------------------" <<  std::endl;
}


// Class Edge

Edge::Edge() : _nodes(), _num(0), _ref(0) {}


Edge::Edge(std::vector<int> nodes, int num, int ref) :
          _nodes(nodes), _num(num), _ref(ref)
{
  assert((_nodes.size() == 2) && "The size of the edge is not equal to 2 !");
}


void Edge::print()
{
  std::cout << "[pt1, pt2] = [" << _nodes[0] << " " << _nodes[1] << "];" << std::endl;
  std::cout << "ref = " << _ref << std::endl;
  std::cout << "num = " << _num << std::endl;
}

std::vector<int> Edge::getNodes()
{
  return _nodes;
}

int Edge::getRef()
{
    return _ref;
}

int Edge::getNum()
{
    return _num;
}

// Class Triangle

Triangle::Triangle() : _nodes(), _num(0), _ref(0) {}

Triangle::Triangle(std::vector<int> nodes, int num, int ref) :
                    _nodes(nodes), _num(num), _ref(ref)
{
    assert((_nodes.size() == 3) && "The size of the vectices (triangle) is not equal to 3 !");
}

void Triangle::print()
{
  std::cout << "[pt1, pt2, pt3] = [" << _nodes[0] << " " << _nodes[1] <<
                                  " " << _nodes[2] << "];" << std::endl;
  std::cout << "ref = " << _ref << std::endl;
  std::cout << "num= " << _num << std::endl;
}

std::vector<int> Triangle::getNodes()
{
  return _nodes;
}


int Triangle::getRef()
{
   return _ref;
}

int Triangle::getNum()
{
   return _num;
}

// Class Triangle

Quadrangle::Quadrangle() : _nodes(), _num(0), _ref(0) {}

Quadrangle::Quadrangle(std::vector<int> nodes, int num, int ref) :
                    _nodes(nodes), _num(num), _ref(ref)
{
    assert((_nodes.size() == 4) && "The size of the vectices (quadrangle) is not equal to 3 !");
}

void Quadrangle::print()
{
  std::cout << "[pt1, pt2, pt3, pt4] = [" << _nodes[0] << " " << _nodes[1] <<
                                  " " << _nodes[2] << _nodes[3] << "];" << std::endl;
  std::cout << "ref = " << _ref << std::endl;
  std::cout << "num= " << _num << std::endl;
}

std::vector<int> Quadrangle::getNodes()
{
  return _nodes;
}


int Quadrangle::getRef()
{
   return _ref;
}

int Quadrangle::getNum()
{
   return _num;
}


 // Class Tetrahedron

Tetrahedron::Tetrahedron() : _nodes(), _num(0),  _ref(0) {}


Tetrahedron::Tetrahedron(std::vector<int> nodes, int num, int ref)
   : _nodes(nodes),  _num(num), _ref(ref)
{
  assert((_nodes.size() == 4) && "The size of the tetrahedron is not equal to 4 !");
}

void Tetrahedron::print()
{
  std::cout << "[pt1, pt2, pt3, pt4] = [" << _nodes[0] << " " << _nodes[1] << " "
                                      << _nodes[2] << " " << _nodes[3] << "];" << std::endl;
  std::cout << "ref = " << _ref << std::endl;
  std::cout << "num= " << _num << std::endl;
}

std::vector<int> Tetrahedron::getNodes()
{
  return _nodes;
}

int Tetrahedron::getRef()
{
   return _ref;
}

int Tetrahedron::getNum()
{
  return _num;
}


// Class Hexahedron

Hexahedron::Hexahedron() : _nodes(), _num(0),  _ref(0) {}


Hexahedron::Hexahedron(std::vector<int> nodes, int num, int ref)
  : _nodes(nodes),  _num(num), _ref(ref)
{
 assert((_nodes.size() == 8) && "The size of the hexahedron is not equal to 8 !");
}

void Hexahedron::print()
{
 std::cout << "[pt1, pt2, pt3, pt4] = [" << _nodes[0] << " " << _nodes[1] << " "
                                     << _nodes[2] << " " << _nodes[3] << "];" << std::endl;
 std::cout << "[pt5, pt6, pt7, pt8] = [" << _nodes[4] << " " << _nodes[5] << " "
                                     << _nodes[6] << " " << _nodes[7] << "];" << std::endl;
 std::cout << "ref = " << _ref << std::endl;
 std::cout << "num= " << _num << std::endl;
}

std::vector<int> Hexahedron::getNodes()
{
 return _nodes;
}

int Hexahedron::getRef()
{
  return _ref;
}

int Hexahedron::getNum()
{
 return _num;
}

// Class Prism

Prism::Prism() : _nodes(), _num(0),  _ref(0) {}


Prism::Prism(std::vector<int> nodes, int num, int ref)
  : _nodes(nodes),  _num(num), _ref(ref)
{
 assert((_nodes.size() == 6) && "The size of the prism is not equal to 6 !");
}

void Prism::print()
{
 std::cout << "[pt1, pt2, pt3, pt4] = [" << _nodes[0] << " " << _nodes[1] << " "
                                     << _nodes[2] << " " << _nodes[3] << "];" << std::endl;
 std::cout << "[pt5, pt6] = [" << _nodes[4] << " " << _nodes[5] << " " << "];" << std::endl;
 std::cout << "ref = " << _ref << std::endl;
 std::cout << "num= " << _num << std::endl;
}

std::vector<int> Prism::getNodes()
{
 return _nodes;
}

int Prism::getRef()
{
  return _ref;
}

int Prism::getNum()
{
 return _num;
}


// Class Hexahedron

Pyramid::Pyramid() : _nodes(), _num(0),  _ref(0) {}


Pyramid::Pyramid(std::vector<int> nodes, int num, int ref)
  : _nodes(nodes),  _num(num), _ref(ref)
{
 assert((_nodes.size() == 5) && "The size of the pyramid is not equal to 5 !");
}

void Pyramid::print()
{
 std::cout << "[pt1, pt2, pt3] = [" << _nodes[0] << " " << _nodes[1] << " "
                                     << _nodes[2] << " "  << "];" << std::endl;
 std::cout << "[pt4, pt5] = [" << _nodes[3] << " " << _nodes[4] << " " << "];" << std::endl;
 std::cout << "ref = " << _ref << std::endl;
 std::cout << "num= " << _num << std::endl;
}

std::vector<int> Pyramid::getNodes()
{
 return _nodes;
}

int Pyramid::getRef()
{
  return _ref;
}

int Pyramid::getNum()
{
 return _num;
}



//  Class Gmesh

Gmesh::Gmesh() {}

int Gmesh::getNumberofNodes()
{
  return _nodes.size();
}

int Gmesh::getNumberofElements()
{
  return _number_of_elements;
}

std::vector<Node> Gmesh::getNodes()
{
  return _nodes;
}

std::vector<Edge> Gmesh::getEdges()
{
  return _edges;
}

std::vector<Triangle> Gmesh::getTriangles()
{
  return _triangles;
}

std::vector<Quadrangle> Gmesh::getQuadrangles()
{
  return _quadrangles;
}

std::vector<Tetrahedron> Gmesh::getTetrahedra()
{
  return _tetrahedra;
}

std::vector<Hexahedron> Gmesh::getHexahedra()
{
  return _hexahedra;
}

std::vector<Prism> Gmesh::getPrisms()
{
  return _prisms;
}

std::vector<Pyramid> Gmesh::getPyramids()
{
  return _pyramids;
}

void Gmesh::readGmesh_MESHformat(const std::string name_mesh)
{
  std::ifstream mesh_file(name_mesh.data());
  if (!mesh_file.is_open())
  {
    std::cout << "Unable to open file " << name_mesh << std::endl;
    abort();
  }

  std::cout << "------------------------" << std::endl;
  std::cout << "Reading mesh " << name_mesh << std::endl;
  std::cout << "MESH Format" << std::endl;
  std::cout << "------------------------" << std::endl;


  std::string file_line;
  int nb_nodes(0), nb_edges(0), nb_triangles(0), nb_tetras(0);
  std::vector<double> vert(3);
  std::vector<int> edg(2), tri(3), tet(4);
  int ref(0), loop_nodes(100), offset_elements(0);

  while (!mesh_file.eof())
  {
    getline(mesh_file, file_line);
    if ((file_line.find("Vertices") != std::string::npos)&&(loop_nodes))
    {
        mesh_file >> nb_nodes;
        std::cout << "Reading vertices (" << nb_nodes << ")" << std::endl;
        for (int i = 1 ; i <= nb_nodes ; i++)
        {
          mesh_file >> vert[0] >> vert[1] >> vert[2] >> ref;
          Node node(vert, i, ref);
          _nodes.push_back(node);
        }
        assert((_nodes.size() == nb_nodes) && "Problem 1 in mesh reading.");
        loop_nodes = 0;
    }
    if (file_line.find("Edges") != std::string::npos)
    {
        mesh_file >> nb_edges;
        std::cout << "Reading edges (" << nb_edges << ")" << std::endl;
        for (int i = 1 ; i <= nb_edges ; i++)
        {
          mesh_file >> edg[0] >> edg[1] >> ref;
          Edge edge(edg, offset_elements + i, ref);
          _edges.push_back(edge);
        }

        offset_elements += nb_edges;
        assert((_edges.size() == nb_edges) && "Problem 2 in mesh reading.");
    }
    if (file_line.find("Triangles") != std::string::npos)
    {
        mesh_file >> nb_triangles;
        std::cout << "Reading triangles (" << nb_triangles << ")" << std::endl;
        for (int i = 1 ; i <= nb_triangles ; i++)
        {
          mesh_file >> tri[0] >> tri[1] >> tri[2] >> ref;
          Triangle triangle(tri, offset_elements + i, ref);
          _triangles.push_back(triangle);
        }

        offset_elements += nb_triangles;
        assert((_triangles.size() == nb_triangles) && "Problem 3 in mesh reading.");
    }
    if (file_line.find("Tetrahedra") != std::string::npos)
    {
        mesh_file >> nb_tetras;
        std::cout << "Reading tetrahedra (" << nb_tetras << ")" << std::endl;
        for (int i = 0 ; i < nb_tetras ; i++)
        {
          mesh_file >> tet[0] >> tet[1] >> tet[2] >> tet[3] >> ref;
          Tetrahedron tetrahedron(tet, offset_elements + i, ref);
          _tetrahedra.push_back(tetrahedron);
        }

        offset_elements += nb_tetras;
        assert((_tetrahedra.size() == nb_tetras) && "Problem 4 in mesh reading.");
    }
  }

   assert(offset_elements == (nb_edges + nb_triangles));
  _number_of_elements = offset_elements;

  mesh_file.close();

  std::cout << "------------------------" << std::endl;
}


void Gmesh::readGmesh_MSHformat(const std::string name_mesh)
{
  std::ifstream mesh_file(name_mesh.data());
  if (!mesh_file.is_open())
  {
    std::cout << "Unable to open file " << name_mesh << std::endl;
    abort();
  }

  std::cout << "------------------------" << std::endl;
  std::cout << "Reading mesh " << name_mesh << std::endl;
  std::cout << "MSH Format"  << std::endl;
  std::cout << "------------------------" << std::endl;


  std::string file_line;
  int nb_nodes(0), nb_elements(0), nb_edges(0), nb_triangles(0), nb_tetras(0);
  std::vector<double> vert(3);
  std::vector<int> edg(2), tri(3), tet(4);
  int ref(0), num(0), loop_nodes(100);

  while (!mesh_file.eof())
  {
    getline(mesh_file, file_line);
    if ((file_line.find("$Nodes") != std::string::npos)&&(loop_nodes))
    {
        mesh_file >> nb_nodes;
        std::cout << "Reading nodes (" << nb_nodes << ")" << std::endl;
        for (int i = 0 ; i < nb_nodes ; ++i)
        {
          mesh_file >> num >> vert[0] >> vert[1] >> vert[2] >> ref;
          Node node(vert, num, 1);
          _nodes.push_back(node);
        }
        assert((_nodes.size() == nb_nodes) && "Problem 1 in mesh reading.");
        loop_nodes = 0;
    }
    if (file_line.find("$Elements") != std::string::npos)
    {
        mesh_file >> nb_elements;
        _number_of_elements = nb_elements;
        std::cout << "Reading elements (" << nb_elements << ")" << std::endl;
        for (int i = 0 ; i < nb_elements ; ++i)
        {
          mesh_file >> edg[0] >> edg[1] >> ref;
          Edge edge(edg, nb_elements, 1);
          _edges.push_back(edge);
        }
        assert((_edges.size() == nb_edges) && "Problem 2 in mesh reading.");
    }
  }

  mesh_file.close();

  std::cout << "------------------------" << std::endl;
}


void Gmesh::readGmesh(const std::string name_mesh)
{
    if (name_mesh.find(".mesh")) {
        Gmesh::readGmesh_MESHformat(name_mesh);
    }
    else if (name_mesh.find(".msh")) {
        Gmesh::readGmesh_MSHformat(name_mesh);
    }
    else {
        std::cout << "Unknown file format" << std::endl;
        abort();
    }

}

void Gmesh::writeGmesh_MESHformat(const std::string name_mesh) const
{
    std::ofstream mesh_file(name_mesh);
    if (!mesh_file.is_open())
    {
       std::cout << "Unable to open file " << name_mesh << std::endl;
       abort();
    }
    else
    {
       std::cout << "------------------------" << std::endl;
       std::cout << "Writing mesh " << name_mesh << std::endl;
       std::cout << "MESH file format"  << std::endl;
       std::cout << "------------------------" << std::endl;
    }

    mesh_file << "MeshVersionFormatted 2" << std::endl;
    mesh_file << "Dimension 3"  << std::endl;
    mesh_file << " " << std::endl;

    mesh_file << "Vertices" << std::endl;
    mesh_file << _nodes.size() << std::endl;

    for (size_t i = 0; i < _nodes.size(); i++){
      Node node(_nodes[i]);
      mesh_file         << (node.getCoordinate())[0]
                << " "  << (node.getCoordinate())[1]
                << " "  << (node.getCoordinate())[2]
                << " "  << node.getRef()
                << std::endl;
    }

    mesh_file << " " << std::endl;
    mesh_file << "Edges" << std::endl;
    mesh_file << _edges.size() << std::endl;

    for (size_t i = 0; i < _edges.size(); i++){
      Edge edge(_edges[i]);
      mesh_file           << (edge.getNodes())[0]
                  << " "  << (edge.getNodes())[1]
                  << " "  << edge.getRef()
                  << std::endl;
    }

    mesh_file << " " << std::endl;
    mesh_file << "Triangles" << std::endl;
    mesh_file << _triangles.size() << std::endl;

    for (size_t i = 0; i < _triangles.size(); i++){
       Triangle tri(_triangles[i]);
       mesh_file          << (tri.getNodes())[0]
                  << " "  << (tri.getNodes())[1]
                  << " "  << (tri.getNodes())[2]
                  << " "  << tri.getRef()
                  << std::endl;
    }

    mesh_file << " "    << std::endl;
    mesh_file << "End"  << std::endl;

    mesh_file.close();

    std::cout << "------------------------" << std::endl;

}

void Gmesh::writeGmesh_MSHformat(const std::string name_mesh) const
{
   std::ofstream mesh_file(name_mesh);
   if (!mesh_file.is_open())
   {
      std::cout << "Unable to open file " << name_mesh << std::endl;
      abort();
   }
   else
   {
      std::cout << "------------------------" << std::endl;
      std::cout << "Writing mesh " << name_mesh << std::endl;
      std::cout << "MSH ASCII file format"  << std::endl;
      std::cout << "------------------------" << std::endl;
   }

   int offset_elements(1);
   int physical_entities(0);

   mesh_file << "$MeshFormat" << std::endl;
   mesh_file << "2.2 0 8" << std::endl;
   mesh_file << "$EndMeshFormat" << std::endl;

   mesh_file << "$Nodes" << std::endl;
   mesh_file << _nodes.size() << std::endl;

   for (size_t i = 0; i < _nodes.size(); i++){
     Node node(_nodes[i]);
     mesh_file << node.getNum()     << " "  << (node.getCoordinate())[0]
                                    << " "  << (node.getCoordinate())[1]
                                    << " "  << (node.getCoordinate())[2]
                                    << std::endl;
   }

   mesh_file << "$EndNodes" << std::endl;
   mesh_file << "$Elements" << std::endl;
   mesh_file << _number_of_elements << std::endl;

   for (size_t i = 0; i < _edges.size(); i++){
     Edge edge(_edges[i]);
     mesh_file << offset_elements << " "  << 1
                                  << " "  << 2 //number of tag
                                  << " "  << physical_entities
                                  << " "  << edge.getRef()
                                  << " "  << (edge.getNodes())[0]
                                  << " "  << (edge.getNodes())[1]
                                  << std::endl;
     offset_elements += 1;
   }

   for (size_t i = 0; i < _triangles.size(); i++){
      Triangle tri(_triangles[i]);
      mesh_file << offset_elements  << " "  << 2
                                    << " "  << 2 //number of tag
                                    << " "  << physical_entities
                                    << " "  << tri.getRef()
                                    << " "  << (tri.getNodes())[0]
                                    << " "  << (tri.getNodes())[1]
                                    << " "  << (tri.getNodes())[2]
                                    << std::endl;
      offset_elements += 1;
   }

   for (size_t i = 0; i < _quadrangles.size(); i++){
      Quadrangle quad(_quadrangles[i]);
      mesh_file << offset_elements  << " "  << 3
                                    << " "  << 2 //number of tag
                                    << " "  << physical_entities
                                    << " "  << quad.getRef()
                                    << " "  << (quad.getNodes())[0]
                                    << " "  << (quad.getNodes())[1]
                                    << " "  << (quad.getNodes())[2]
                                    << " "  << (quad.getNodes())[3]
                                    << std::endl;
      offset_elements += 1;
   }

   for (size_t i = 0; i < _tetrahedra.size(); i++){
      Tetrahedron tet(_tetrahedra[i]);
      mesh_file << offset_elements  << " "  << 4
                                    << " "  << 2 //number of tag
                                    << " "  << physical_entities
                                    << " "  << tet.getRef()
                                    << " "  << (tet.getNodes())[0]
                                    << " "  << (tet.getNodes())[1]
                                    << " "  << (tet.getNodes())[2]
                                    << " "  << (tet.getNodes())[3]
                                    << std::endl;
      offset_elements += 1;
   }

   for (size_t i = 0; i < _hexahedra.size(); i++){
      Hexahedron hexa(_hexahedra[i]);
      mesh_file << offset_elements  << " "  << 5
                                    << " "  << 2 //number of tag
                                    << " "  << physical_entities
                                    << " "  << hexa.getRef()
                                    << " "  << (hexa.getNodes())[0]
                                    << " "  << (hexa.getNodes())[1]
                                    << " "  << (hexa.getNodes())[2]
                                    << " "  << (hexa.getNodes())[3]
                                    << " "  << (hexa.getNodes())[4]
                                    << " "  << (hexa.getNodes())[5]
                                    << " "  << (hexa.getNodes())[6]
                                    << " "  << (hexa.getNodes())[7]
                                    << std::endl;
      offset_elements += 1;
   }

   for (size_t i = 0; i < _prisms.size(); i++){
      Prism pri(_prisms[i]);
      mesh_file << offset_elements  << " "  << 6
                                    << " "  << 2 //number of tag
                                    << " "  << physical_entities
                                    << " "  << pri.getRef()
                                    << " "  << (pri.getNodes())[0]
                                    << " "  << (pri.getNodes())[1]
                                    << " "  << (pri.getNodes())[2]
                                    << " "  << (pri.getNodes())[3]
                                    << " "  << (pri.getNodes())[4]
                                    << " "  << (pri.getNodes())[5]
                                    << std::endl;
      offset_elements += 1;
   }

   for (size_t i = 0; i < _pyramids.size(); i++){
      Pyramid py(_pyramids[i]);
      mesh_file << offset_elements  << " "  << 7
                                    << " "  << 2 //number of tag
                                    << " "  << physical_entities
                                    << " "  << py.getRef()
                                    << " "  << (py.getNodes())[0]
                                    << " "  << (py.getNodes())[1]
                                    << " "  << (py.getNodes())[2]
                                    << " "  << (py.getNodes())[3]
                                    << " "  << (py.getNodes())[4]
                                    << std::endl;
      offset_elements += 1;
   }

   mesh_file << "$EndElements" << std::endl;

   mesh_file.close();

   std::cout << "------------------------" << std::endl;
}

void Gmesh::writeGmesh(const std::string name_mesh, const int format) const
{
    if (format == 1) {
        Gmesh::writeGmesh_MESHformat(name_mesh);
    }
    else if (format == 2) {
        Gmesh::writeGmesh_MSHformat(name_mesh);
    }
    else {
        std::cout << "Unknown file format" << std::endl;
        abort();
    }
}

void Gmesh::getInfo()
{
   std::cout << "----------------------------" << std::endl;
   std::cout << "Informations about Gmsh mesh" << std::endl;
   std::cout << "----------------------------" << std::endl;
   std::cout << " * Numbers of vetices : " << _nodes.size() << std::endl;
   std::cout << " * Numbers of edges : " << _edges.size() << std::endl;
   std::cout << " * Numbers of triangles : " << _triangles.size() << std::endl;
   std::cout << " * Numbers of quadrangles : " << _quadrangles.size() << std::endl;
   std::cout << " * Numbers of tetrahedra : " << _tetrahedra.size() << std::endl;
   std::cout << " * Numbers of hexahedra : " << _hexahedra.size() << std::endl;
   std::cout << " * Numbers of prisms : " << _prisms.size() << std::endl;
   std::cout << " * Numbers of pyramids : " << _pyramids.size() << std::endl;
   std::cout << "----------------------------" << std::endl;
}

void Gmesh::addNode(const Node& node)
{
   _nodes.push_back(node);
}

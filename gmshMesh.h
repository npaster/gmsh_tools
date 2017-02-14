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

#ifndef GMSHMESH_H
#define GMSHMESH_H

#include<vector>
#include<string>
#include "gmshElement.h"

class Gmesh
{
   protected:
      size_t _dim_topology;
      std::vector<Node> _nodes;
      std::vector<Vertice> _vertices;
      std::vector<Edge> _edges;
      std::vector<Triangle> _triangles;
      std::vector<Quadrangle> _quadrangles;
      std::vector<Tetrahedron> _tetrahedra;
      std::vector<Hexahedron> _hexahedra;
      std::vector<Prism> _prisms;
      std::vector<Pyramid> _pyramids;
      size_t _number_of_elements;
      void readGmesh_MEDITformat(const std::string name_mesh);
      void writeGmesh_MEDITformat(const std::string name_mesh) const;
      void readGmesh_MSHformat(const std::string name_mesh);
      void writeGmesh_MSHformat(const std::string name_mesh) const;

      void convertInDiscontinuousMesh1();
      void convertInDiscontinuousMesh2();
      void convertInDiscontinuousMesh3();


   public:
      Gmesh();
      void readGmesh(const std::string name_mesh);
      void writeGmesh(const std::string name_mesh, const size_t format) const;
      void getInfo() const;
      size_t getNumberofNodes() const;
      size_t getNumberofElements() const;
      std::vector<Node> getNodes() const;
      std::vector<Vertice> getVertices() const;
      std::vector<Edge> getEdges() const;
      std::vector<Triangle> getTriangles() const;
      std::vector<Quadrangle> getQuadrangles() const;
      std::vector<Hexahedron> getHexahedra() const;
      std::vector<Tetrahedron> getTetrahedra() const;
      std::vector<Prism> getPrisms() const;
      std::vector<Pyramid> getPyramids() const;

      void addNode(const Node& node);
      void addVertices(const Vertice& vertice);
      void addTriangle(const Triangle& triangle);
      void addQuadrangle(const Quadrangle& quad);
      void addHexahedron(const Hexahedron& hexa);
      void addTetrahedon(const Tetrahedron& tetra);
      void addPrism(const Prism& prism);
      void addPyramid(const Pyramid& pyramid);

      void convertInDiscontinuousMesh();
      void computeDeformed();

};

#endif

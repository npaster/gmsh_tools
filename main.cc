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

#include<iostream>
#include<string>
#include <math.h>
#include "gmshMesh.h"
#include "gmshData.h"
#include "gmshElement.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 2)
    {
      cout << "Please, enter the name of your mesh .. " << endl;
      abort();
    }

  Gmesh mesh;
  const string name_mesh(argv[1]);
  mesh.readGmesh(name_mesh);

  mesh.getInfo();
  cout << endl;

  mesh.writeGmesh("test.msh", 2);

  Gmesh mesh2(mesh);

  mesh2.convertInDiscontinuousMesh();
  mesh2.computeDeformed();

  mesh2.writeGmesh("test2.msh", 2);

  NodeData data;

  data.changeNbComposante(1);

  std::vector<Node> v_node= mesh2.getNodes();

  for (size_t i = 0; i < v_node.size(); i++) {
     std::vector<double> value = {1.0 + (rand() % 10)} ;
     std::vector<double> coor = {0.1*(rand() % 10), 0.1*(rand() % 10), 0.0};
     Node nodetmp(coor, v_node.size() +1 +i, 1 );
     Data dat(v_node.size() +1 +i , value);
     //data.addData(v_node[i].getIndex(), value );
     data.addSubData(dat, nodetmp);
  }

  data.saveNodeData("result5.msh", mesh2);

  ElementData data2;

  data2.changeNbComposante(1);

  std::vector<Triangle> v= mesh.getTriangles();

  for (size_t i = 0; i < v.size(); i++) {
     std::vector<double> value = {1.0 + i} ;
     data2.addData(v[i].getIndex(), value );
  }



  data2.saveElementData("result4.msh", mesh);

  return 0;
}

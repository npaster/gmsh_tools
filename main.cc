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
#include "gmsh_mesh.h"
#include "savedata.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 2)
    {
      cout << "Please, enter the name of your mesh .. " << endl;
      abort();
    }

  cout << "Mesh" << endl;
  Gmesh mesh;
  const string name_mesh(argv[1]);
  mesh.readGmesh(name_mesh);

  mesh.getInfo();
  cout << endl;

  mesh.writeGmesh("test.msh", 2);

  Data data, data2;

  data.modifyNbComposante(1);

  std::vector<Node> v_node= mesh.getNodes();

  for (size_t i = 0; i < v_node.size(); i++) {
     std::vector<double> value = {1.0 + i} ;
     data.addData(v_node[i].getNum(), value );
  }


  data2.modifyNbComposante(1);

  std::vector<Triangle> v= mesh.getTriangles();

  for (size_t i = 0; i < v.size(); i++) {
     std::vector<double> value = {1.0 + i} ;
     data2.addData(v[i].getNum(), value );
  }

  NodeData result(data);
  ElementData result2(data2);
  result.saveNodeData("result5.msh", mesh);
  result2.saveElementData("result4.msh", mesh);

  return 0;
}

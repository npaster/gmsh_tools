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

 #include "gmshMesh.h"
 #include "gmshData.h"
 #include "gmshElement.h"
 #include<vector>
 #include<string>
 #include<utility>
 #include<fstream>
 #include<iostream>

// Class Data

Data::Data() : _nb_composante(0), _data() {}

Data::Data(const size_t nb_composante, const std::vector< std::pair<size_t, std::vector<double> > >& data)
            : _nb_composante(nb_composante), _data(data) {}

size_t Data::getNbComposante() const
{
   return _nb_composante;
}

std::vector< std::pair<size_t, std::vector<double> > > Data::getData() const
{
   return _data;
}

void Data::addData(const size_t num, const std::vector<double>& values)
{
   _data.push_back(std::make_pair(num, values));
}


void Data::modifyNbComposante(const size_t nb_composante)
{
   _nb_composante = nb_composante;
}

// Class GenericData
GenericData::GenericData() : _data(), _time_value(0.0), _title("  ") {}
GenericData::GenericData(const Data& data) : _data(data), _time_value(0.0), _title("\" Unknown title \" ") {}
GenericData::GenericData(const Data& data, const double time_value, const std::string title)
            : _data(data), _time_value(time_value), _title(title) {}

Data GenericData::getData() const {return _data;}

double GenericData::getTime() const {return _time_value;}
std::string GenericData::getTitle() const {return _title;}

void GenericData::changeTime(const double time) {_time_value = time;}
void GenericData::changeTitle(const std::string title) {_title = title;}

// Class NodeData

NodeData::NodeData() : GenericData() {}

NodeData::NodeData(const Data& data) : GenericData(data) {}

NodeData::NodeData(const Data& data, const double time_value, const std::string title)
      : GenericData(data, time_value, title) {}

void NodeData::writeNodeData(const std::string name_mesh) const
{
   std::ofstream mesh_file;
   mesh_file.open(name_mesh, std::ofstream::out | std::ofstream::app);
   if (!mesh_file.is_open())
   {
      std::cout << "Unable to open file " << name_mesh << std::endl;
      abort();
   }
   else
   {
      std::cout << "------------------------" << std::endl;
      std::cout << "Writing Results " << name_mesh << std::endl;
      std::cout << "MSH ASCII file format"  << std::endl;
      std::cout << "------------------------" << std::endl;
   }

   mesh_file << "$NodeData" << std::endl;
   mesh_file << 1 << std::endl;  // string tag

   mesh_file << _title  << std::endl; // name of the view
   mesh_file << 1 << std::endl; // real tag
   mesh_file << _time_value << std::endl; // time value
   mesh_file << 3 << std::endl; // integer tag
   mesh_file << 0 << std::endl;  // time Step

   const std::vector< std::pair<size_t, std::vector<double> > > result=  _data.getData();

   mesh_file << _data.getNbComposante() << std::endl;
   mesh_file << result.size() << std::endl;

   for (size_t i = 0; i < result.size(); i++) {
      mesh_file   << result[i].first   << " ";
      for (size_t j = 0; j < _data.getNbComposante() ; j++) {
         mesh_file   << (result[i].second).at(j)   << " ";
      }
      mesh_file   <<   std::endl;
   }

   mesh_file << "$EndNodeData" << std::endl;
   mesh_file.close();

}

void NodeData::saveNodeData(const std::string name_mesh, const Gmesh& mesh) const
{
   mesh.writeGmesh(name_mesh, 2);
   writeNodeData(name_mesh);
}

// Class ElementData

ElementData::ElementData() : GenericData() {}

ElementData::ElementData(const Data& data) : GenericData(data) {}

ElementData::ElementData(const Data& data, const double time_value, const std::string title)
      : GenericData(data, time_value, title) {}

void ElementData::writeElementData(const std::string name_mesh) const
{
   std::ofstream mesh_file;
   mesh_file.open(name_mesh, std::ofstream::out | std::ofstream::app);
   if (!mesh_file.is_open())
   {
      std::cout << "Unable to open file " << name_mesh << std::endl;
      abort();
   }
   else
   {
      std::cout << "------------------------" << std::endl;
      std::cout << "Writing Results " << name_mesh << std::endl;
      std::cout << "MSH ASCII file format"  << std::endl;
      std::cout << "------------------------" << std::endl;
   }

   mesh_file << "$ElementData" << std::endl;
   mesh_file << 1 << std::endl;  // string tag

   mesh_file <<  _title  << std::endl; // name of the view
   mesh_file << 1 << std::endl; // real tag
   mesh_file << _time_value << std::endl; // time value
   mesh_file << 3 << std::endl; // integer tag
   mesh_file << 0 << std::endl;  // time Step

   const std::vector< std::pair<size_t, std::vector<double> > > result=  _data.getData();

   mesh_file << _data.getNbComposante() << std::endl;
   mesh_file << result.size() << std::endl;

   for (size_t i = 0; i < result.size(); i++) {
      mesh_file   << result[i].first   << " ";
      for (size_t j = 0; j < _data.getNbComposante() ; j++) {
         mesh_file   << (result[i].second).at(j)   << " ";
      }
      mesh_file   <<   std::endl;
   }

   mesh_file << "$EndElementData" << std::endl;
   mesh_file.close();

}

void ElementData::saveElementData(const std::string name_mesh, const Gmesh& mesh) const
{
   mesh.writeGmesh(name_mesh, 2);
   writeElementData(name_mesh);
}

//Class ElementNodeData


ElementNodeData::ElementNodeData() : GenericData() {}

ElementNodeData::ElementNodeData(const Data& data) : GenericData(data) {}

ElementNodeData::ElementNodeData(const Data& data, const double time_value, const std::string title)
      : GenericData(data, time_value, title) {}

void ElementNodeData::writeElementNodeData(const std::string name_mesh) const
{
   std::ofstream mesh_file;
   mesh_file.open(name_mesh, std::ofstream::out | std::ofstream::app);
   if (!mesh_file.is_open())
   {
      std::cout << "Unable to open file " << name_mesh << std::endl;
      abort();
   }
   else
   {
      std::cout << "------------------------" << std::endl;
      std::cout << "Writing Results " << name_mesh << std::endl;
      std::cout << "MSH ASCII file format"  << std::endl;
      std::cout << "------------------------" << std::endl;
   }

   mesh_file << "$ElementNodeData" << std::endl;
   mesh_file << 1 << std::endl;  // string tag

   mesh_file << _title  << std::endl; // name of the view
   mesh_file << 1 << std::endl; // real tag
   mesh_file << _time_value << std::endl; // time value
   mesh_file << 3 << std::endl; // integer tag
   mesh_file << 0 << std::endl;  // time Step

   const std::vector< std::pair<size_t, std::vector<double> > > result=  _data.getData();

   mesh_file << _data.getNbComposante() << std::endl;
   mesh_file << result.size() << std::endl;

   for (size_t i = 0; i < result.size(); i++) {
      mesh_file   << result[i].first   << " ";
      for (size_t j = 0; j < _data.getNbComposante() ; j++) {
         mesh_file   << (result[i].second).at(j)   << " ";
      }
      mesh_file   <<   std::endl;
   }

   mesh_file << "$EndElementNodeData" << std::endl;
   mesh_file.close();

}

void ElementNodeData::saveElementNodeData(const std::string name_mesh, const Gmesh& mesh) const
{
   mesh.writeGmesh(name_mesh, 2);
   writeElementNodeData(name_mesh);
}

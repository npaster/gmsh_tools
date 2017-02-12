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
 #include<utility>

class Data
{
  protected:
     int _nb_composante;
     std::vector< std::pair<int, std::vector<double> > > _data;

  public:
     Data();
     Data(const int nb_composante, const std::vector< std::pair<int, std::vector<double> > >& data);
     int getNbComposante() const;
     std::vector< std::pair<int, std::vector<double> > > getData() const;
     void addData(const int num, const std::vector<double>& values);
     void modifyNbComposante(const int nb_composante);
};

class GenericData
{
   protected:
      std::string _title;
      double _time_value;
      Data _data;

   public:
      GenericData();
      GenericData(const Data& data);
      GenericData(const Data& data, const double time_value, const std::string title);
      Data getData() const;
      double getTime() const;
      std::string getTitle() const;
      void changeTime(const double time);
      void changeTitle(const std::string title);
};


class NodeData : public GenericData
{
  private:
     void writeNodeData(const std::string name_mesh) const;

  public:
       NodeData();
       NodeData(const Data& data);
       NodeData(const Data& data, const double time_value, const std::string title);
       void saveNodeData(const std::string name_mesh, const Gmesh& mesh) const;
};

class ElementData : public GenericData
{
  private:
     void writeElementData(const std::string name_mesh) const;

  public:
       ElementData();
       ElementData(const Data& data);
       ElementData(const Data& data, const double time_value, const std::string title);
       void saveElementData(const std::string name_mesh, const Gmesh& mesh) const;
};

class ElementNodeData : public GenericData
{
  private:
     void writeElementNodeData(const std::string name_mesh) const;

  public:
       ElementNodeData();
       ElementNodeData(const Data& data);
       ElementNodeData(const Data& data, const double time_value, const std::string title);
       void saveElementNodeData(const std::string name_mesh, const Gmesh& mesh) const;
};

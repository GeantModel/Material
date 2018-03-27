

#include "DetGeometry.hh"

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4Isotope* C12 = new G4Isotope("C12",6,12);
    G4Isotope* C13 = new G4Isotope("C13",6,13);

    G4Element* C = new G4Element("Carbon", "C", 2);
    C->AddIsotope(C12,0.98);
    C->AddIsotope(C13,0.02);

    std::ofstream fout("../result.txt");
    fout<<C;

   // G4Material* CsI = new G4Material("CsI",4*g/cm3,2,kStateSolid);
  //  CsI->AddElement(nist->FindElement(3),1);
   // CsI->AddElement(nist->FindElement(4),5);
  //  fout<<CsI<<'\n';
    fout<<'\n'<<nist->FindOrBuildMaterial("G4_CESIUM_IODIDE");
     //return physWorld;
}



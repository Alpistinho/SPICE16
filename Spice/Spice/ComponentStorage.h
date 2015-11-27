#pragma once
#include <string>
#include <map>
#include <complex>
#include <vector>
#include "storage.h"
#include "Component.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "CurrentControlledCurrentSource.h"
#include "CurrentControlledVoltageSource.h"
#include "BJT.h"
#include "CurrentSource.h"
#include "inductiveCoupling.h"
#include "OpAmp.h"
#include "VoltageControlledCurrentSource.h"
#include "VoltageControlledVoltageSource.h"
#include "VoltageSource.h"
#include "Node.h"
#include "NodeStorage.h"
#include "Branch.h"
#include "BranchStorage.h"

namespace spiceSimulator {

	class ComponentStorage :
		public Storage
	{
	public:
		friend class FrequencySimulation;
		ComponentStorage(void);
		~ComponentStorage(void);

		//adds a resistor to the model. Returns the generated identifier.
		unsigned addResistor(std::string, std::string, double);
		unsigned addCapacitor(std::string, std::string, double);
		unsigned addInductor(std::string, std::string, double);
		unsigned addCurrentControlledCurrentSource(std::string, std::string, std::string, std::string, double);
		unsigned addVoltageControlledCurrentSource(std::string, std::string, std::string, std::string, double);
		unsigned addCurrentControlledVoltageSource(std::string, std::string, std::string, std::string, double);
		unsigned addVoltageControlledVoltageSource(std::string, std::string, std::string, std::string, double);
		unsigned addCurrentSource(std::string, std::string, double, double); // will need to be extended for time-domain
		unsigned addVoltageSource(std::string, std::string, double, double);
		unsigned addOpAmp(std::string, std::string, std::string, std::string);
		unsigned addBJT(std::string, std::string, std::string, double, double, double, double, double, double);
	
		bool removeComponent(unsigned); //removes a component indicated by the passed identifier
		bool removeComponent(Component*); //removes a component indicated by the passed pointer

		Component getComponentByIdentifier(unsigned); //returns the component indicated by the passed identifier
		void getFrequencySystem(std::vector<std::vector<std::complex<double>>>*, double); 
		void allocateNodeNumbers();
		unsigned long getSystemSize();


	private:

		unsigned long componentIdentifier; //limits the component amount to 4294967295. Hardly a problem
		unsigned long elementsAmount;
		unsigned long branchesNeededAmount; //how many branches will have its current calculated.
	
		NodeStorage nodeStorage;
		BranchStorage branchStorage;
		std::map<unsigned long, Component*> componentMap;

	
	};

}
/* +---------------------------------------------------------------------------+
	 |                     Mobile Robot Programming Toolkit (MRPT)               |
	 |                          http://www.mrpt.org/                             |
	 |                                                                           |
	 | Copyright (c) 2005-2016, Individual contributors, see AUTHORS file        |
	 | See: http://www.mrpt.org/Authors - All rights reserved.                   |
	 | Released under BSD License. See details in http://www.mrpt.org/License    |
	 +---------------------------------------------------------------------------+ */

#ifndef CGRAPHSLAMENGINE_ROS_IMPL_H
#define CGRAPHSLAMENGINE_ROS_IMPL_H
namespace mrpt { namespace graphslam {

template<class GRAPH_t>
CGraphSlamEngine_ROS<GRAPH_t>::CGraphSlamEngine_ROS(
		ros::NodeHandle* nh,
		const std::string& config_file,
		const std::string& rawlog_fname/* ="" */,
		const std::string& fname_GT /* ="" */,
		mrpt::graphslam::CWindowManager* win_manager /* = NULL */,
		mrpt::graphslam::deciders::CNodeRegistrationDecider<GRAPH_t>* node_reg /* = NULL */,
		mrpt::graphslam::deciders::CEdgeRegistrationDecider<GRAPH_t>* edge_reg /* = NULL */,
		mrpt::graphslam::optimizers::CGraphSlamOptimizer<GRAPH_t>* optimizer /* = NULL */):
	m_nh(nh),
	parent::CGraphSlamEngine(
			config_file,
			rawlog_fname,
			fname_GT,
			win_manager,
			node_reg,
			edge_reg,
			optimizer)
{

	this->initClass();

}

template<class GRAPH_t>
CGraphSlamEngine_ROS<GRAPH_t>::~CGraphSlamEngine_ROS() {
}

template<class GRAPH_t>
bool CGraphSlamEngine_ROS<GRAPH_t>::execGraphSlamStep(
		mrpt::obs::CObservationPtr& observation,
		size_t& rawlog_entry) { 
	parent::execGraphSlamStep(observation, rawlog_entry);
}

template<class GRAPH_t>
bool CGraphSlamEngine_ROS<GRAPH_t>::execGraphSlamStep(
		mrpt::obs::CActionCollectionPtr& action,
		mrpt::obs::CSensoryFramePtr& observations,
		mrpt::obs::CObservationPtr& observation,
		size_t& rawlog_entry) { 

	// call parent method
	parent::execGraphSlamStep(
			action, observations, observation, rawlog_entry);

	// notify of the neighbors
}

template<class GRAPH_t>
void CGraphSlamEngine_ROS<GRAPH_t>::initClass() {
	using namespace mrpt::graphslam;

	// in case of ROS specific deciders/optimizers (they inherit from the CDeciderOrOptimizer_ROS interface)
	// set the NodeHandle
	{
	 	CRegistrationDeciderOrOptimizer_ROS<GRAPH_t>* dec_opt_ros =
	 	 	dynamic_cast<CRegistrationDeciderOrOptimizer_ROS<GRAPH_t>*>(this->m_node_registrar);

	 	if (dec_opt_ros) {
	 	 	dec_opt_ros->setNodeHandle(m_nh);
	 	}
	}
	{
		CRegistrationDeciderOrOptimizer_ROS<GRAPH_t>* dec_opt_ros =
	 	 	dynamic_cast<CRegistrationDeciderOrOptimizer_ROS<GRAPH_t>*>(this->m_edge_registrar);
		if (dec_opt_ros) {
	 		dec_opt_ros->setNodeHandle(m_nh);
		}
	}
	{
		CRegistrationDeciderOrOptimizer_ROS<GRAPH_t>* dec_opt_ros =
			dynamic_cast<CRegistrationDeciderOrOptimizer_ROS<GRAPH_t>*>(this->m_optimizer);
		if (dec_opt_ros) {
	 		dec_opt_ros->setNodeHandle(m_nh);
		}
	}
	
}



} } // end of namespaces

#endif /* end of include guard: CGRAPHSLAMENGINE_ROS_IMPL_H */
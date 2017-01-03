#ifndef CREGISTRATIONDECIDEROROPTIMIZER_ROS_H
#define CREGISTRATIONDECIDEROROPTIMIZER_ROS_H

#include <ros/ros.h>

#include <mrpt/utils/COutputLogger.h>

namespace mrpt { namespace graphslam {

/**\brief Interface class that all ROS-specific deciders/optimizers can inherit
 * from.
 */
template<class GRAPH_t=typename mrpt::graphs::CNetworkOfPoses2DInf>
class CRegistrationDeciderOrOptimizer_ROS : public virtual mrpt::utils::COutputLogger
{
public:
	CRegistrationDeciderOrOptimizer_ROS();
	virtual ~CRegistrationDeciderOrOptimizer_ROS();

	virtual void setNodeHandle(ros::NodeHandle* nh);

protected:
	/**\brief NodeHandle instance
	 */
	ros::NodeHandle* m_nh;


};


} } // end of namespaces

#include "mrpt_graphslam_2d/interfaces/CRegistrationDeciderOrOptimizer_ROS_impl.h"

#endif /* end of include guard: CREGISTRATIONDECIDEROROPTIMIZER_ROS_H */

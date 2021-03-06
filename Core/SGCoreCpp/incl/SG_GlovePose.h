// ----------------------------------------------------------------------------------
// Contains position and rotation data of a SenseGlove's exoskeleton,
// along with accessors for relevant variables.
// @author: Max Lammers
// ----------------------------------------------------------------------------------

#pragma once

#include "SGCore.h"

#include <vector>
#include <string>
#include "Fingers.h"
#include "Vect3D.h"
#include "Quat.h"
#include "SG_Model.h"
#include "SG_HandProfile.h"

namespace SGCore
{
	namespace SG
	{
		/// <summary> Represents a pose of a Sense Glove exoskeleton. </summary>
		struct SGCORE_API SG_GlovePose
		{

		public:

			//--------------------------------------------------------------------------------
			// Properties

			/// <summary> Positions of each glove joint, relative to the Glove's Origin. </summary>
			std::vector< std::vector< Kinematics::Vect3D > > jointPositions;

			/// <summary> Quaternion rotation of each glove joint, relative to the Glove Origin. </summary>
			std::vector< std::vector< Kinematics::Quat > > jointRotations;

			/// <summary> Glove joint angles in euler notation, relative to the last segment. </summary>
			/// <remarks> Essentially sensor angles, though placed in their proper xyz notation </remarks>
			std::vector< std::vector< Kinematics::Vect3D > > gloveAngles;


			//--------------------------------------------------------------------------------
			// Construction

			/// <summary> Basic Constructor </summary>
			SG_GlovePose();

			/// <summary> Creates a new instance of a SG_GlovePose </summary>
			SG_GlovePose(std::vector< std::vector< Kinematics::Vect3D > > positions,
				std::vector< std::vector< Kinematics::Quat > > rotations,
				std::vector< std::vector< Kinematics::Vect3D > > jointAngles);

			/// <summary> Basic Destructor </summary>
			~SG_GlovePose();

			/// <summary> Returns an idle pose for the Sense Glove if no data can be found. </summary>
			static SG_GlovePose IdlePose(SG_Model glove);


			//--------------------------------------------------------------------------------
			// Class Methods

			///<summary> The position of the tip of the 'thimbles', the furthest link on each glove link. </summary>
			std::vector< Kinematics::Vect3D > ThimblePositions();

			///<summary> The (quaternion) rotation of the 'thimbles', the furthest link on each link.  </summary>
			std::vector< Kinematics::Quat > ThimbleRotations();


			///<summary> Sum of the Sensor angles in each (xyz) direction. "Total Pronation / Flexion / Abduction" </summary>
			std::vector< Kinematics::Vect3D > TotalGloveAngles();


			/// <summary> Calculate fingertip positions based on a user profile. </summary>
			std::vector<Kinematics::Vect3D> CalculateFingerTips(SG_HandProfile profile);

			/// <summary> Calculate fingertip positions, knowing the offset between thimble and fingertips. </summary>
			std::vector<Kinematics::Vect3D> CalculateFingerTips(std::vector<Kinematics::Vect3D> fingerOffsets);


			//--------------------------------------------------------------------------------
			// Serialization

			//TODO: Serialization / Deserialization


		};
	}
}

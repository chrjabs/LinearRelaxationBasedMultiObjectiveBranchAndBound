/**
* \author Nicolas Forget
*
* This class describe a feasible solution of the initial problem.
*/

#pragma once
#include <stdlib.h>
#include <list>
#include <vector>
#include "Point.h"
#include "Model.h"

class Solution {
private:
	std::vector<int> variableVector; //!< variable vector of the solution. Always integer.
	std::vector<int> objectiveVector; //!< objective vector of the solution. Always integer, as the objective coefficients are integer.
	bool dominated; //!< true if this solution is dominated by another one

public:
	/*! \brief Default constructor of a solution.
	 *
	 * This function creates an empty solution.
	 */
	Solution();

	/*! \brief Construct a solution from an extreme point of the LinearRelaxation
	 *
	 * This function creates a solution from an extreme point of the LinearRelaxation, by extracting its pre-image and
	 * objective vector.
	 * \param pts Point. The point the solution is created from.
	 */
	Solution(Point& pts, MathematicalModel* lp);

	/*! \brief Check whether this Solution dominates another Solution y.
	 *
	 * This function check whether this Solution dominates another Solution y, by doing component-wise comparisons
	 * \param y Solution. The Solution used for comparison.
	 */
	bool dominate(Solution& y);


	/*! \brief Returns the value of a specific objective function.
	 *
	 * This function returns the value of the objective vector at coordinate obj. This correspond to the value of
	 * this point in objective obj.
	 * \param obj integer. The index of the objective to look at.
	 * \return the value of this objective, as a double.
	 */
	int get_objVector(int obj);

	/*! \brief Prints the solution.
	 *
	 * This function prints the objective vector of the solution.
	 */
	void print();

	/*! \brief Discard the solution.
	 *
	 * Discard this solution by setting dominated to true.
	 */
	void discard();

	/*! \brief Checks whether the solution is discarded.
	 *
	 * This function checks whether this solution is discarded by looking at member dominated. If it is true, the solution
	 * is discarded.
	 * \return true if the solution is discarded, false otherwise.
	 */
	bool isDiscarded();
};
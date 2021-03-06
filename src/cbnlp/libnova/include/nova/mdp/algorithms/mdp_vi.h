/**
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2015 Kyle Hollins Wray, University of Massachusetts
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 *  this software and associated documentation files (the "Software"), to deal in
 *  the Software without restriction, including without limitation the rights to
 *  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 *  the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 *  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 *  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 *  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#ifndef NOVA_MDP_VI__H
#define NOVA_MDP_VI__H


#include <nova/mdp/mdp.h>
#include <nova/mdp/policies/mdp_value_function.h>

namespace nova {

/**
 *  The necessary variables to perform value iteration on an MDP within nova.
 *  @param  VInitial        The initial value function, mapping states (n-array) to floats.
 *  @param  currentHorizon  The current horizon updated after each iteration.
 *  @param  V               The value of the states (n-array).
 *  @param  VPrime          The value of the states (n-array) copy.
 *  @param  pi              The action to take at each state (n-array).
 */
typedef struct NovaMDPVI {
    float *VInitial;

    unsigned int currentHorizon;

    float *V;
    float *VPrime;
    unsigned int *pi;
} MDPVI;

/**
 *  Execute all steps of VI for the MDP model specified.
 *  @param  mdp         The MDP object.
 *  @param  vi          The MDPVI object containing algorithm variables.
 *  @param  policy      The resulting value function policy. This will be modified.
 *  @return Returns zero upon success, non-zero otherwise.
 */
extern "C" int mdp_vi_execute(const MDP *mdp, MDPVI *vi, MDPValueFunction *policy);

/**
 *  Step 1/4: The initialization step of VI. This sets up the V and pi variables.
 *  @param  mdp         The MDP object.
 *  @param  vi          The MDPVI object containing algorithm variables.
 *  @return Returns zero upon success, non-zero otherwise.
 */
extern "C" int mdp_vi_initialize(const MDP *mdp, MDPVI *vi);

/**
 *  Step 2/4: The update step of VI. This applies the VI procedure once.
 *  @param  mdp         The MDP object.
 *  @param  vi          The MDPVI object containing algorithm variables.
 *  @return Returns zero upon success, non-zero otherwise.
 */
extern "C" int mdp_vi_update(const MDP *mdp, MDPVI *vi);

/**
 *  Step 3/4: The get resultant policy step of VI. This retrieves the values of states (V) and
 *  the corresponding actions at each state (pi).
 *  @param  mdp         The MDP object.
 *  @param  vi          The MDPVI object containing algorithm variables.
 *  @param  policy      The resulting value function policy. This will be modified.
 *  @return Returns zero upon success, non-zero otherwise.
 */
extern "C" int mdp_vi_get_policy(const MDP *mdp, MDPVI *vi, MDPValueFunction *policy);

/**
 *  Step 4/4: The uninitialization step of VI. This sets up the V and pi variables.
 *  @param  mdp         The MDP object.
 *  @param  vi          The MDPVI object containing algorithm variables.
 *  @return Returns zero upon success, non-zero otherwise.
 */
extern "C" int mdp_vi_uninitialize(const MDP *mdp, MDPVI *vi);

};


#endif // NOVA_MDP_VI__H


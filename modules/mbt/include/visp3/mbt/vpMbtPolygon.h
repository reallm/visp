/****************************************************************************
 *
 * $Id$
 *
 * This file is part of the ViSP software.
 * Copyright (C) 2005 - 2014 by INRIA. All rights reserved.
 * 
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * ("GPL") version 2 as published by the Free Software Foundation.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact INRIA about acquiring a ViSP Professional 
 * Edition License.
 *
 * See http://www.irisa.fr/lagadic/visp/visp.html for more information.
 * 
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact
 * INRIA at visp@inria.fr
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Description:
 * Implements a polygon of the model used by the model-based tracker.
 *
 * Authors:
 * Nicolas Melchior
 * Romain Tallonneau
 * Eric Marchand
 * Aurelien Yol
 *
 *****************************************************************************/

/*!
 \file vpMbtPolygon.h
 \brief Implements a polygon of the model used by the model-based tracker.
*/

#ifndef vpMbtPolygon_HH
#define vpMbtPolygon_HH

#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMeterPixelConversion.h>
#include <visp3/core/vpPixelMeterConversion.h>
#include <visp3/core/vpPolygon3D.h>

#include <vector>

/*!
  \class vpMbtPolygon
  
  \brief Implementation of a polygon of the model used by the model-based tracker.

  \ingroup ModelBasedTracking

 */
class VISP_EXPORT vpMbtPolygon : public vpPolygon3D
{
public:
  //! Index of the polygon. Cannot be unsigned int because default value is -1.
  int index;
  //! flag to specify whether the face is visible or not
  bool isvisible;
  //! flag to specify whether the face is appearing or not
  bool isappearing;
  //! Flag to specify if the visibility of the polygon depends also of the current level of detail (LOD)
  bool useLod;
  //! Threshold for minimum line length in pixel to consider if the line is visible or not in LOD case
  double minLineLengthThresh;
  //! Threshold for minimum polygon area in pixel to consider if the polygon is visible or not in LOD case
  double minPolygonAreaThresh;
  //! Name of the polygon
  std::string name;

public: 
            vpMbtPolygon() ;
            vpMbtPolygon(const vpMbtPolygon& mbtp) ;
            virtual       ~vpMbtPolygon() ;
  
   /*!
    Get the index of the face.

    \return index : the index of the face.
  */
  inline    int           getIndex() const {return index ;}

  /*!
   Get the name of the face.

   \return Name of the face.
   */
  inline    std::string   getName() const {return name;}

  inline    bool          isAppearing() const {return isappearing;}
  virtual   bool          isVisible(const vpHomogeneousMatrix &cMo, const double alpha, const bool &modulo = false,
		  const vpCameraParameters &cam = vpCameraParameters(), const vpImage<unsigned char> &I = vpImage<unsigned char>());
            bool          isVisible() const {return isvisible;}

            vpMbtPolygon& operator=(const vpMbtPolygon& mbtp) ;
  
  /*!
    Set the index of the face.

    \param i : the new index of the face.
  */
  virtual inline void     setIndex(const int i ) { index = i ; } 

  // Due to a doxygen warning include the sample code in the doc, we remove the inline and put the doc in the *.cpp file
  void	  setLod(const bool use_lod);
  /*!
    Set the threshold for the minimum line length to be considered as visible in the LOD
    (level of detail) case. This threshold is only used when setLoD() is turned on.

    \param min_line_length : threshold for the minimum line length in pixel. When a single line that doesn't
    belong to a face is considered by the tracker, this line is tracked only if its lenght in pixel is
    greater than \e min_line_length.

    \sa setLoD()
   */
  inline		 void	  setMinLineLengthThresh(const double min_line_length) {
    this->minLineLengthThresh = min_line_length;
  }
  /*!
    Set the minimum polygon area to be considered as visible in the LOD (level of detail)
    case. This threshold is only used when setLoD() is turned on.

    \param min_polygon_area : threshold for the minimum polygon area in pixel. When a face
    is considered by the tracker, this face is tracked only if its area in pixel is
    greater than \e min_polygon_area.

    \sa setLoD()
  */
  inline		 void	  setMinPolygonAreaThresh(const double min_polygon_area) {
    this->minPolygonAreaThresh = min_polygon_area;
  }

  /*!
   Set the name of the face.

   \param face_name : name of the face.
   */
  inline        void        setName(const std::string &face_name) {
    this->name = face_name;
  }
  
#ifdef VISP_BUILD_DEPRECATED_FUNCTIONS
public:
  /*!
    @name Deprecated functions
  */
  bool      isVisible(const vpHomogeneousMatrix &cMo, const bool &depthTest = false) ;
#endif
};

#endif

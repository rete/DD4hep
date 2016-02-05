// $Id: $
//==========================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------------
// Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
// All rights reserved.
//
// For the licensing terms see $DD4hepINSTALL/LICENSE.
// For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
//
// Author     : F.Gaede
//
//==========================================================================

#ifndef DD4HEP_DetType_H
#define DD4HEP_DetType_H

/// Namespace for the AIDA detector description toolkit
namespace DD4hep {

  /** Helper class for encoding sub detector types in a flag word.
   *  Example:<br>
   *  DetType type( DetType::TRACKER | DetType::STRIP | DetType::BARREL ) ; <br>
   *  type.is( DetType::EMCALO  ) ; // false <br>
   *  type.isNot( DetType::CALORIMETER  ) ; // true <br>
   *  type.is( DetType::STRIP | DetType::BARREL ) ; // true <br>
   *
   * @author F.gaede, DESY
   * @date 05.02.2016
   * @version $Id: $
   */
  class DetType {

    friend std::ostream& operator<<(std::ostream& os , const DetType& t   ) ;

  public:

    enum {
      TRACKER      = 1 <<  0, 
      CALORIMETER  = 1 <<  1, 
      CHERENKOV    = 1 <<  2, 
      ENDCAP	   = 1 <<  3, 
      BARREL	   = 1 <<  4, 
      FORWARD	   = 1 <<  5, 
      VERTEX	   = 1 <<  6, 
      STRIP	   = 1 <<  7, 
      PIXEL	   = 1 <<  8, 
      GASEOUS	   = 1 <<  9, 
      WIRE	   = 1 << 10, 
      EMCALO	   = 1 << 11, 
      HADCALO	   = 1 << 12, 
      MUON	   = 1 << 13, 
      SUPPORT      = 1 << 14
    } ;
    

    /// default c'tor
    DetType( ) : _type(0) {}

    /** initialize with a ulong containing all properties, e.g.
     *  DetType type( DetType::TRACKER | DetType::STRIP | DetType::BARREL ) ;
     */
    DetType( unsigned long types ) : _type( types ){}
    
    /// set additional properties
    inline void set(  unsigned long prop ) {
      _type |= prop ;
    }
    
    /// unset the given properties
    inline void unset(  unsigned long prop ) {
      _type &= ~prop ;
    }
    
    /// true if detector has all properties
    inline bool is( unsigned long prop ) const {
      return ( _type & prop ) == prop ;
    }

    /// true if detector has none of the given properties
    inline bool isNot( unsigned long prop ) const {
      return ( _type & prop ) == 0 ;
    }

  private:
    unsigned long _type ;
  } ;
  
  inline std::ostream& operator<<( std::ostream& os , const DetType& t  ){
    
    os << "DetType( " << std::hex << "0x" << t._type << ") : " << std::dec ;
    if( t.is( DetType::TRACKER      ) ) os << "TRACKER, " ;
    if( t.is( DetType::CALORIMETER  ) ) os << "CALORIMETER, " ;
    if( t.is( DetType::CHERENKOV    ) ) os << "CHERENKOV, " ;
    if( t.is( DetType::ENDCAP	    ) ) os << "ENDCAP, " ;
    if( t.is( DetType::BARREL	    ) ) os << "BARREL, " ;
    if( t.is( DetType::FORWARD	    ) ) os << "FORWARD, " ;
    if( t.is( DetType::VERTEX	    ) ) os << "VERTEX, " ;
    if( t.is( DetType::STRIP	    ) ) os << "STRIP, " ;
    if( t.is( DetType::PIXEL	    ) ) os << "PIXEL, " ;
    if( t.is( DetType::GASEOUS	    ) ) os << "GASEOUS, " ;
    if( t.is( DetType::WIRE	    ) ) os << "WIRE, " ;
    if( t.is( DetType::EMCALO	    ) ) os << "EMCALO, " ;
    if( t.is( DetType::HADCALO	    ) ) os << "HADCALO, " ;
    if( t.is( DetType::MUON	    ) ) os << "MUON, " ;
    if( t.is( DetType::SUPPORT      ) ) os << "SUPPORT, " ;
    return os ;
  }

  
} /* End namespace DD4hep        */

#endif    /* DD4HEP_DETECTOR_H      */
/* Created by Language version: 6.2.0 */
/* VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib.h"
#undef PI
 
#include "md1redef.h"
#include "section.h"
#include "md2redef.h"

#if METHOD3
extern int _method3;
#endif

#undef exp
#define exp hoc_Exp
extern double hoc_Exp();
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gmax _p[0]
#define conductance _p[1]
#define m_instances _p[2]
#define m_q10Settings_q10Factor _p[3]
#define m_q10Settings_experimentalTemp _p[4]
#define m_reverseRate_rate _p[5]
#define m_reverseRate_midpoint _p[6]
#define m_reverseRate_scale _p[7]
#define m_forwardRate_rate _p[8]
#define m_forwardRate_midpoint _p[9]
#define m_forwardRate_scale _p[10]
#define h_instances _p[11]
#define h_q10Settings_q10Factor _p[12]
#define h_q10Settings_experimentalTemp _p[13]
#define h_reverseRate_rate _p[14]
#define h_reverseRate_midpoint _p[15]
#define h_reverseRate_scale _p[16]
#define h_forwardRate_rate _p[17]
#define h_forwardRate_midpoint _p[18]
#define h_forwardRate_scale _p[19]
#define m_q10Settings_q10 _p[20]
#define m_reverseRate_r _p[21]
#define m_forwardRate_x _p[22]
#define m_forwardRate_r _p[23]
#define m_rateScale _p[24]
#define m_alpha _p[25]
#define m_beta _p[26]
#define m_fcond _p[27]
#define m_inf _p[28]
#define m_tau _p[29]
#define h_q10Settings_q10 _p[30]
#define h_reverseRate_r _p[31]
#define h_forwardRate_r _p[32]
#define h_rateScale _p[33]
#define h_alpha _p[34]
#define h_beta _p[35]
#define h_fcond _p[36]
#define h_inf _p[37]
#define h_tau _p[38]
#define conductanceScale _p[39]
#define fopenHHrates _p[40]
#define fopenHHtauInf _p[41]
#define fopenHHratesTau _p[42]
#define fopenHHratesInf _p[43]
#define fopen _p[44]
#define g _p[45]
#define m_q _p[46]
#define h_q _p[47]
#define temperature _p[48]
#define ena _p[49]
#define ina _p[50]
#define rate_m_q _p[51]
#define rate_h_q _p[52]
#define Dm_q _p[53]
#define Dh_q _p[54]
#define v _p[55]
#define _g _p[56]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static int _hoc_rates();
 static int _mechtype;
extern int nrn_get_mechtype();
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range();
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 ret(1.);
}
 /* connect user functions to hoc names */
 static IntFunc hoc_intfunc[] = {
 "setdata_Na_NML2", _hoc_setdata,
 "rates_Na_NML2", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "conductance_Na_NML2", "uS",
 "m_q10Settings_experimentalTemp_Na_NML2", "K",
 "m_reverseRate_rate_Na_NML2", "megahertz",
 "m_reverseRate_midpoint_Na_NML2", "mV",
 "m_reverseRate_scale_Na_NML2", "mV",
 "m_forwardRate_rate_Na_NML2", "megahertz",
 "m_forwardRate_midpoint_Na_NML2", "mV",
 "m_forwardRate_scale_Na_NML2", "mV",
 "h_q10Settings_experimentalTemp_Na_NML2", "K",
 "h_reverseRate_rate_Na_NML2", "megahertz",
 "h_reverseRate_midpoint_Na_NML2", "mV",
 "h_reverseRate_scale_Na_NML2", "mV",
 "h_forwardRate_rate_Na_NML2", "megahertz",
 "h_forwardRate_midpoint_Na_NML2", "mV",
 "h_forwardRate_scale_Na_NML2", "mV",
 "m_reverseRate_r_Na_NML2", "megahertz",
 "m_forwardRate_r_Na_NML2", "megahertz",
 "m_alpha_Na_NML2", "megahertz",
 "m_beta_Na_NML2", "megahertz",
 "m_tau_Na_NML2", "ms",
 "h_reverseRate_r_Na_NML2", "megahertz",
 "h_forwardRate_r_Na_NML2", "megahertz",
 "h_alpha_Na_NML2", "megahertz",
 "h_beta_Na_NML2", "megahertz",
 "h_tau_Na_NML2", "ms",
 "g_Na_NML2", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double h_q0 = 0;
 static double m_q0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(), nrn_init(), nrn_state();
 static void nrn_cur(), nrn_jacob();
 
static int _ode_count(), _ode_map(), _ode_spec(), _ode_matsol();
 
#define _cvode_ieq _ppvar[3]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static char *_mechanism[] = {
 "6.2.0",
"Na_NML2",
 "gmax_Na_NML2",
 "conductance_Na_NML2",
 "m_instances_Na_NML2",
 "m_q10Settings_q10Factor_Na_NML2",
 "m_q10Settings_experimentalTemp_Na_NML2",
 "m_reverseRate_rate_Na_NML2",
 "m_reverseRate_midpoint_Na_NML2",
 "m_reverseRate_scale_Na_NML2",
 "m_forwardRate_rate_Na_NML2",
 "m_forwardRate_midpoint_Na_NML2",
 "m_forwardRate_scale_Na_NML2",
 "h_instances_Na_NML2",
 "h_q10Settings_q10Factor_Na_NML2",
 "h_q10Settings_experimentalTemp_Na_NML2",
 "h_reverseRate_rate_Na_NML2",
 "h_reverseRate_midpoint_Na_NML2",
 "h_reverseRate_scale_Na_NML2",
 "h_forwardRate_rate_Na_NML2",
 "h_forwardRate_midpoint_Na_NML2",
 "h_forwardRate_scale_Na_NML2",
 0,
 "m_q10Settings_q10_Na_NML2",
 "m_reverseRate_r_Na_NML2",
 "m_forwardRate_x_Na_NML2",
 "m_forwardRate_r_Na_NML2",
 "m_rateScale_Na_NML2",
 "m_alpha_Na_NML2",
 "m_beta_Na_NML2",
 "m_fcond_Na_NML2",
 "m_inf_Na_NML2",
 "m_tau_Na_NML2",
 "h_q10Settings_q10_Na_NML2",
 "h_reverseRate_r_Na_NML2",
 "h_forwardRate_r_Na_NML2",
 "h_rateScale_Na_NML2",
 "h_alpha_Na_NML2",
 "h_beta_Na_NML2",
 "h_fcond_Na_NML2",
 "h_inf_Na_NML2",
 "h_tau_Na_NML2",
 "conductanceScale_Na_NML2",
 "fopenHHrates_Na_NML2",
 "fopenHHtauInf_Na_NML2",
 "fopenHHratesTau_Na_NML2",
 "fopenHHratesInf_Na_NML2",
 "fopen_Na_NML2",
 "g_Na_NML2",
 0,
 "m_q_Na_NML2",
 "h_q_Na_NML2",
 0,
 0};
 static Symbol* _na_sym;
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 57, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-05;
 	m_instances = 3;
 	m_q10Settings_q10Factor = 3;
 	m_q10Settings_experimentalTemp = 279.45;
 	m_reverseRate_rate = 4;
 	m_reverseRate_midpoint = -65;
 	m_reverseRate_scale = -18;
 	m_forwardRate_rate = 1;
 	m_forwardRate_midpoint = -40;
 	m_forwardRate_scale = 10;
 	h_instances = 1;
 	h_q10Settings_q10Factor = 3;
 	h_q10Settings_experimentalTemp = 279.45;
 	h_reverseRate_rate = 1;
 	h_reverseRate_midpoint = -35;
 	h_reverseRate_scale = 10;
 	h_forwardRate_rate = 0.07;
 	h_forwardRate_midpoint = -65;
 	h_forwardRate_scale = -20;
 	_prop->param = _p;
 	_prop->param_size = 57;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 _Na_NML2_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_dparam_size(_mechtype, 4);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Na_NML2 /home/boris/nC_projects/ghk_nernst/generatedNEURON/x86_64/Na_NML2.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=Na_NML2 type=MOD_Na_NML2)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
static rates();
 
static int _ode_spec1(), _ode_matsol1();
 static int _slist1[2], _dlist1[2];
 static int states();
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargs_ ) ;
   Dm_q = rate_m_q ;
   Dh_q = rate_h_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Dm_q = Dm_q  / (1. - dt*( 0.0 )) ;
 Dh_q = Dh_q  / (1. - dt*( 0.0 )) ;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    m_q = m_q - dt*(- ( rate_m_q ) ) ;
    h_q = h_q - dt*(- ( rate_h_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _p, _ppvar, _thread, _nt ) double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt; {
   m_q10Settings_q10 = pow( m_q10Settings_q10Factor , ( ( temperature - m_q10Settings_experimentalTemp ) / 10.0 ) ) ;
   m_reverseRate_r = m_reverseRate_rate * exp ( ( v - m_reverseRate_midpoint ) / m_reverseRate_scale ) ;
   m_forwardRate_x = ( v - m_forwardRate_midpoint ) / m_forwardRate_scale ;
   m_forwardRate_r = m_forwardRate_rate * m_forwardRate_x / ( 1.0 - exp ( 0.0 - m_forwardRate_x ) ) ;
   m_rateScale = m_q10Settings_q10 ;
   m_alpha = m_forwardRate_r ;
   m_beta = m_reverseRate_r ;
   m_fcond = pow( m_q , m_instances ) ;
   m_inf = m_alpha / ( m_alpha + m_beta ) ;
   m_tau = 1.0 / ( ( m_alpha + m_beta ) * m_rateScale ) ;
   h_q10Settings_q10 = pow( h_q10Settings_q10Factor , ( ( temperature - h_q10Settings_experimentalTemp ) / 10.0 ) ) ;
   h_reverseRate_r = h_reverseRate_rate / ( 1.0 + exp ( 0.0 - ( v - h_reverseRate_midpoint ) / h_reverseRate_scale ) ) ;
   h_forwardRate_r = h_forwardRate_rate * exp ( ( v - h_forwardRate_midpoint ) / h_forwardRate_scale ) ;
   h_rateScale = h_q10Settings_q10 ;
   h_alpha = h_forwardRate_r ;
   h_beta = h_reverseRate_r ;
   h_fcond = pow( h_q , h_instances ) ;
   h_inf = h_alpha / ( h_alpha + h_beta ) ;
   h_tau = 1.0 / ( ( h_alpha + h_beta ) * h_rateScale ) ;
   rate_m_q = ( m_inf - m_q ) / m_tau ;
   rate_h_q = ( h_inf - h_q ) / h_tau ;
    return 0; }
 
static int _hoc_rates() {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt ) ;
 ret(_r);
}
 
static int _ode_count(_type) int _type;{ return 2;}
 
static int _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static int _ode_map(_ieq, _pv, _pvdot, _pp, _ppd, _atol, _type) int _ieq, _type; double** _pv, **_pvdot, *_pp, *_atol; Datum* _ppd; { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static int _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h_q = h_q0;
  m_q = m_q0;
 {
   rates ( _threadargs_ ) ;
   temperature = celsius + 273.15 ;
   m_q = m_inf ;
   h_q = h_inf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   conductanceScale = 1.0 ;
   fopenHHrates = m_fcond * h_fcond ;
   fopenHHtauInf = 1.0 ;
   fopenHHratesTau = 1.0 ;
   fopenHHratesInf = 1.0 ;
   fopen = conductanceScale * fopenHHrates * fopenHHtauInf * fopenHHratesTau * fopenHHratesInf ;
   g = conductance * fopen ;
   g = gmax * fopen ;
   ina = g * ( v - ena ) ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
 double _break, _save;
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
  ena = _ion_ena;
 { {
 for (; t < _break; t += dt) {
   states(_p, _ppvar, _thread, _nt);
  
}}
 t = _save;
 } }}

}

static terminal(){}

static _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m_q) - _p;  _dlist1[0] = &(Dm_q) - _p;
 _slist1[1] = &(h_q) - _p;  _dlist1[1] = &(Dh_q) - _p;
_first = 0;
}

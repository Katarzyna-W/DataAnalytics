
// Code generated by stanc v2.26.1
#include <stan/model/model_header.hpp>
namespace macro_2_fit_model_namespace {


inline void validate_positive_index(const char* var_name, const char* expr,
                                    int val) {
  if (val < 1) {
    std::stringstream msg;
    msg << "Found dimension size less than one in simplex declaration"
        << "; variable=" << var_name << "; dimension size expression=" << expr
        << "; expression value=" << val;
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}

inline void validate_unit_vector_index(const char* var_name, const char* expr,
                                       int val) {
  if (val <= 1) {
    std::stringstream msg;
    if (val == 1) {
      msg << "Found dimension size one in unit vector declaration."
          << " One-dimensional unit vector is discrete"
          << " but the target distribution must be continuous."
          << " variable=" << var_name << "; dimension size expression=" << expr;
    } else {
      msg << "Found dimension size less than one in unit vector declaration"
          << "; variable=" << var_name << "; dimension size expression=" << expr
          << "; expression value=" << val;
    }
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}


using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using std::pow;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::model_base_crtp;
using stan::model::rvalue;
using stan::model::cons_list;
using stan::model::index_uni;
using stan::model::index_max;
using stan::model::index_min;
using stan::model::index_min_max;
using stan::model::index_multi;
using stan::model::index_omni;
using stan::model::nil_index_list;
using namespace stan::math;
using stan::math::pow; 

stan::math::profile_map profiles__;
static int current_statement__= 0;
static const std::vector<string> locations_array__ = {" (found before start of program)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 8, column 2 to column 13)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 9, column 2 to column 12)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 10, column 2 to column 22)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 14, column 2 to column 36)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 25, column 2 to column 20)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 26, column 2 to column 26)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 28, column 4 to column 59)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 29, column 4 to column 50)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 27, column 17 to line 30, column 3)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 27, column 2 to line 30, column 3)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 18, column 2 to column 23)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 19, column 2 to column 25)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 20, column 2 to column 25)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 21, column 2 to column 33)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 2, column 2 to column 8)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 3, column 9 to column 10)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 3, column 2 to column 18)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 4, column 18 to column 19)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 4, column 2 to column 21)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 14, column 9 to column 10)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 25, column 9 to column 10)",
                                                      " (in 'C:/Users/Karolina/DA_2021/8MINIP~1/macro_2_fit.stan', line 26, column 23 to column 24)"};



class macro_2_fit_model final : public model_base_crtp<macro_2_fit_model> {

 private:
  int N;
  Eigen::Matrix<double, -1, 1> tbond;
  std::vector<double> unemp_data;
 
 public:
  ~macro_2_fit_model() { }
  
  inline std::string model_name() const final { return "macro_2_fit_model"; }

  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.26.1", "stancflags = "};
  }
  
  
  macro_2_fit_model(stan::io::var_context& context__,
                    unsigned int random_seed__ = 0,
                    std::ostream* pstream__ = nullptr) : model_base_crtp(0) {
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static const char* function__ = "macro_2_fit_model_namespace::macro_2_fit_model";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      current_statement__ = 15;
      context__.validate_dims("data initialization","N","int",
          context__.to_vec());
      N = std::numeric_limits<int>::min();
      
      current_statement__ = 15;
      N = context__.vals_i("N")[(1 - 1)];
      current_statement__ = 16;
      validate_non_negative_index("tbond", "N", N);
      current_statement__ = 17;
      context__.validate_dims("data initialization","tbond","double",
          context__.to_vec(N));
      tbond = Eigen::Matrix<double, -1, 1>(N);
      stan::math::fill(tbond, std::numeric_limits<double>::quiet_NaN());
      
      {
        std::vector<local_scalar_t__> tbond_flat__;
        current_statement__ = 17;
        assign(tbond_flat__, nil_index_list(), context__.vals_r("tbond"),
          "assigning variable tbond_flat__");
        current_statement__ = 17;
        pos__ = 1;
        current_statement__ = 17;
        for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
          current_statement__ = 17;
          assign(tbond, cons_list(index_uni(sym1__), nil_index_list()),
            tbond_flat__[(pos__ - 1)], "assigning variable tbond");
          current_statement__ = 17;
          pos__ = (pos__ + 1);}
      }
      current_statement__ = 18;
      validate_non_negative_index("unemp_data", "N", N);
      current_statement__ = 19;
      context__.validate_dims("data initialization","unemp_data","double",
          context__.to_vec(N));
      unemp_data = std::vector<double>(N, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 19;
      assign(unemp_data, nil_index_list(), context__.vals_r("unemp_data"),
        "assigning variable unemp_data");
      current_statement__ = 20;
      validate_non_negative_index("mu", "N", N);
      current_statement__ = 21;
      validate_non_negative_index("log_lik", "N", N);
      current_statement__ = 22;
      validate_non_negative_index("unemp_posterior", "N", N);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    num_params_r__ = 0U;
    
    try {
      num_params_r__ += 1;
      num_params_r__ += 1;
      num_params_r__ += 1;
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
  }
  template <bool propto__, bool jacobian__, typename VecR, typename VecI, stan::require_vector_like_t<VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    static const char* function__ = "macro_2_fit_model_namespace::log_prob";
(void) function__;  // suppress unused var warning

    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning

    
    try {
      local_scalar_t__ alpha;
      alpha = DUMMY_VAR__;
      
      current_statement__ = 1;
      alpha = in__.scalar();
      local_scalar_t__ beta;
      beta = DUMMY_VAR__;
      
      current_statement__ = 2;
      beta = in__.scalar();
      local_scalar_t__ sigma;
      sigma = DUMMY_VAR__;
      
      current_statement__ = 3;
      sigma = in__.scalar();
      current_statement__ = 3;
      if (jacobian__) {
        current_statement__ = 3;
        sigma = stan::math::lb_constrain(sigma, 0, lp__);
      } else {
        current_statement__ = 3;
        sigma = stan::math::lb_constrain(sigma, 0);
      }
      Eigen::Matrix<local_scalar_t__, -1, 1> mu;
      mu = Eigen::Matrix<local_scalar_t__, -1, 1>(N);
      stan::math::fill(mu, DUMMY_VAR__);
      
      current_statement__ = 4;
      assign(mu, nil_index_list(), add(multiply(tbond, beta), alpha),
        "assigning variable mu");
      {
        current_statement__ = 11;
        lp_accum__.add(normal_lpdf<propto__>(alpha, 5, 1));
        current_statement__ = 12;
        lp_accum__.add(lognormal_lpdf<propto__>(beta, 0, 1));
        current_statement__ = 13;
        lp_accum__.add(exponential_lpdf<propto__>(sigma, 1));
        current_statement__ = 14;
        lp_accum__.add(normal_lpdf<propto__>(unemp_data, mu, sigma));
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, stan::require_std_vector_vt<std::is_floating_point, VecVar>* = nullptr>
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.resize(0);
    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    static const char* function__ = "macro_2_fit_model_namespace::write_array";
(void) function__;  // suppress unused var warning

    (void) function__;  // suppress unused var warning

    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning

    
    try {
      double alpha;
      alpha = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 1;
      alpha = in__.scalar();
      double beta;
      beta = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 2;
      beta = in__.scalar();
      double sigma;
      sigma = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 3;
      sigma = in__.scalar();
      current_statement__ = 3;
      sigma = stan::math::lb_constrain(sigma, 0);
      Eigen::Matrix<double, -1, 1> mu;
      mu = Eigen::Matrix<double, -1, 1>(N);
      stan::math::fill(mu, std::numeric_limits<double>::quiet_NaN());
      
      vars__.emplace_back(alpha);
      vars__.emplace_back(beta);
      vars__.emplace_back(sigma);
      if (logical_negation((primitive_value(emit_transformed_parameters__) ||
            primitive_value(emit_generated_quantities__)))) {
        return ;
      } 
      current_statement__ = 4;
      assign(mu, nil_index_list(), add(multiply(tbond, beta), alpha),
        "assigning variable mu");
      if (emit_transformed_parameters__) {
        for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
          vars__.emplace_back(mu[(sym1__ - 1)]);}
      } 
      if (logical_negation(emit_generated_quantities__)) {
        return ;
      } 
      Eigen::Matrix<double, -1, 1> log_lik;
      log_lik = Eigen::Matrix<double, -1, 1>(N);
      stan::math::fill(log_lik, std::numeric_limits<double>::quiet_NaN());
      
      std::vector<double> unemp_posterior;
      unemp_posterior = std::vector<double>(N, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 10;
      for (int i = 1; i <= N; ++i) {
        current_statement__ = 7;
        assign(log_lik, cons_list(index_uni(i), nil_index_list()),
          normal_lpdf<false>(unemp_data[(i - 1)], mu[(i - 1)], sigma),
          "assigning variable log_lik");
        current_statement__ = 8;
        assign(unemp_posterior, cons_list(index_uni(i), nil_index_list()),
          normal_rng(mu[(i - 1)], sigma, base_rng__),
          "assigning variable unemp_posterior");}
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        vars__.emplace_back(log_lik[(sym1__ - 1)]);}
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        vars__.emplace_back(unemp_posterior[(sym1__ - 1)]);}
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, stan::require_std_vector_t<VecVar>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline void transform_inits_impl(const stan::io::var_context& context__,
                                   VecI& params_i__, VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.clear();
    vars__.reserve(num_params_r__);
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      double alpha;
      alpha = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 1;
      alpha = context__.vals_r("alpha")[(1 - 1)];
      double beta;
      beta = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 2;
      beta = context__.vals_r("beta")[(1 - 1)];
      double sigma;
      sigma = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 3;
      sigma = context__.vals_r("sigma")[(1 - 1)];
      double sigma_free__;
      sigma_free__ = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 3;
      sigma_free__ = stan::math::lb_free(sigma, 0);
      vars__.emplace_back(alpha);
      vars__.emplace_back(beta);
      vars__.emplace_back(sigma_free__);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__.clear();
    names__.emplace_back("alpha");
    names__.emplace_back("beta");
    names__.emplace_back("sigma");
    names__.emplace_back("mu");
    names__.emplace_back("log_lik");
    names__.emplace_back("unemp_posterior");
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    dimss__.clear();
    dimss__.emplace_back(std::vector<size_t>{});
    
    dimss__.emplace_back(std::vector<size_t>{});
    
    dimss__.emplace_back(std::vector<size_t>{});
    
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(N)});
    
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(N)});
    
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(N)});
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "alpha");
    param_names__.emplace_back(std::string() + "beta");
    param_names__.emplace_back(std::string() + "sigma");
    if (emit_transformed_parameters__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "mu" + '.' + std::to_string(sym1__));
        }}
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "log_lik" + '.' + std::to_string(sym1__));
        }}
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "unemp_posterior" + '.' + std::to_string(sym1__));
        }}
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "alpha");
    param_names__.emplace_back(std::string() + "beta");
    param_names__.emplace_back(std::string() + "sigma");
    if (emit_transformed_parameters__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "mu" + '.' + std::to_string(sym1__));
        }}
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "log_lik" + '.' + std::to_string(sym1__));
        }}
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "unemp_posterior" + '.' + std::to_string(sym1__));
        }}
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"alpha\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"beta\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"sigma\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"mu\",\"type\":{\"name\":\"vector\",\"length\":" << N << "},\"block\":\"transformed_parameters\"},{\"name\":\"log_lik\",\"type\":{\"name\":\"vector\",\"length\":" << N << "},\"block\":\"generated_quantities\"},{\"name\":\"unemp_posterior\",\"type\":{\"name\":\"array\",\"length\":" << N << ",\"element_type\":{\"name\":\"real\"}},\"block\":\"generated_quantities\"}]";
    return s__.str();
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"alpha\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"beta\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"sigma\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"mu\",\"type\":{\"name\":\"vector\",\"length\":" << N << "},\"block\":\"transformed_parameters\"},{\"name\":\"log_lik\",\"type\":{\"name\":\"vector\",\"length\":" << N << "},\"block\":\"generated_quantities\"},{\"name\":\"unemp_posterior\",\"type\":{\"name\":\"array\",\"length\":" << N << ",\"element_type\":{\"name\":\"real\"}},\"block\":\"generated_quantities\"}]";
    return s__.str();
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      std::vector<double> vars_vec(vars.size());
      std::vector<int> params_i;
      write_array_impl(base_rng, params_r, params_i, vars_vec,
          emit_transformed_parameters, emit_generated_quantities, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i) {
        vars.coeffRef(i) = vars_vec[i];
      }
    }

    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      write_array_impl(base_rng, params_r, params_i, vars, emit_transformed_parameters, emit_generated_quantities, pstream);
    }

    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      Eigen::Matrix<int, -1, 1> params_i;
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }

    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }
  

    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits_impl(context, params_i, params_r_vec, pstream);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i) {
        params_r.coeffRef(i) = params_r_vec[i];
      }
    }
    inline void transform_inits(const stan::io::var_context& context,
                                std::vector<int>& params_i,
                                std::vector<double>& vars,
                                std::ostream* pstream = nullptr) const final {
      transform_inits_impl(context, params_i, vars, pstream);
    }        

};
}
using stan_model = macro_2_fit_model_namespace::macro_2_fit_model;

#ifndef USING_R

// Boilerplate
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

stan::math::profile_map& get_stan_profile_data() {
  return macro_2_fit_model_namespace::profiles__;
}

#endif



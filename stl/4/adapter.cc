template <class AdaptablePredicate>
class unary_negate{
private:
    AdaptablePredicate pred;
public:
    typedef typename AdaptablePredicate::argument_type argument_type;
    typedef typename AdaptablePredicate::result_type result_type;

    unary_negate(const AdaptablePredicate& x): pred(x) {}
    bool operator()(const argument_type& x) const{
        return !pred(x);
    }
};

template <class AdaptablePredicate>
inline unary_negate<AdaptablePredicate>
not1(const AdaptablePredicate& pred){
    return unary_negate<AdaptablePredicate>(pred);
}

template <class Arg, class Result>
class pointer_to_unary_function:public unary_function<Arg, Result>{
    private:
        Result (*ptr)(Arg);
    public:
        pointer_to_unary_function(){}
        pointer_to_unary_function(Result (*x)(Arg)) ptr(x){}
        Result operator()(Arg x) const {return ptr(x);}

};

template <class Arg, class Result>
inline pointer_to_unary_function<Arg, Result>
ptr_fun(Result (*x)(Arg)){
    return pointer_to_unary_function<Arg, Result>(x);
}




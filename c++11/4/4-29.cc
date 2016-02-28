class OuterType{
    struct InnerType{int i;};

    InnerType GetInner();
    InnerType it;
};

auto OuterType:: GetInner() -> InnerType{
    return it;
}

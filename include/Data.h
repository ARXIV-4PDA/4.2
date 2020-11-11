#ifndef DATA_H
#define DATA_H
#include <unordered_map>
#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <fstream>

struct Load{
    float year_max=0.0f;
    float year_min=0.0f;

    float summer_decline=0.0f;
    float summer_peak=0.0f;

    float winter_decline=0.0f;
    float winter_peak=0.0f;

    float deviations=0.0f;
};

class Imput_data{
    public:
    float P_DES=0.0f;
    float YRNT_DES=0.0f;
    float delta_cost_oil=0.0f;
    float price_DT=0.0f;
    std::unordered_map<int,Load> year_data;

    float P_under_concluded_agreements=0.0f;
    float coefficient_of_simultaneity=0.0f;

    std::vector<std::string> Name_setting;
    std::vector<std::string> string_namber;

    float Own_needs=0.0f;
    float Optim_download=0.0f;
    float Min_ekcpel_download=0.0f;
    float Min_dop_download=0.0f;

    float Carex_cec=0.0f;

    Imput_data(){};
    void input(std::string name);
    void print();
};

int load_1(void *data, int argc, char **argv, char **azColName){
     std::vector<std::vector<float>> * data_=reinterpret_cast< std::vector<std::vector<float>> *>(data);
     data_->push_back({0});
     data_->back().clear();
     for(int i=0;i<24;i++){
         data_->back().push_back(std::stof(argv[i+1]));
        // std::cout<<data_->size()<<"|"<< data_->back().back()<<"|"<<i+1<<std::endl;
     }
    return 0;
};


int load_2(void *data, int argc, char **argv, char **azColName){
     std::vector<std::vector<float>> * data_=reinterpret_cast< std::vector<std::vector<float>> *>(data);
     data_->push_back({0});
     data_->back().clear();
     for(int i=0;i<15;i++){
         data_->back().push_back(std::stof(argv[i+1]));
        // std::cout<<data_->size()<<"|"<< data_->back().back()<<"|"<<i+1<<std::endl;
     }
    return 0;
};

int load_3(void *data, int argc, char **argv, char **azColName){
     std::vector<std::vector<float>> * data_=reinterpret_cast< std::vector<std::vector<float>> *>(data);
     data_->push_back({0});
     data_->back().clear();
     data_->back().push_back(0);
     data_->back().push_back(0);
     for(int i=0;i<2;i++){
         data_->back().push_back(std::stof(argv[i+2]));
        // std::cout<<data_->size()<<"|"<< data_->back().back()<<"|"<<i+1<<std::endl;
     }
    return 0;
};

int load_4(void *data, int argc, char **argv, char **azColName){
     std::vector<std::vector<float>> * data_=reinterpret_cast< std::vector<std::vector<float>> *>(data);
     data_->push_back({0});
     data_->back().clear();
     data_->back().push_back(0);
     data_->back().push_back(0);
     for(int i=0;i<2;i++){
         data_->back().push_back(std::stof(argv[i+2]));
        // std::cout<<data_->size()<<"|"<< data_->back().back()<<"|"<<i+1<<std::endl;
     }
    return 0;
};

int load_5(void *data, int argc, char **argv, char **azColName){
     std::vector<std::vector<float>> * data_=reinterpret_cast< std::vector<std::vector<float>> *>(data);
     data_->push_back({0});
     data_->back().clear();
     data_->back().push_back(0);
     for(int i=0;i<2;i++){
         data_->back().push_back(std::stof(argv[i+1]));
        // std::cout<<data_->size()<<"|"<< data_->back().back()<<"|"<<i+1<<std::endl;
     }
    return 0;
};

struct P{
    std::vector<std::vector<float>> P_ptreb{0};
    std::vector<std::vector<float>> P_YRNT_proc{0};
    std::vector<std::vector<float>> P_import_dgy{0};
    std::vector<std::vector<float>> P_russian_dgy{0};
    std::vector<std::vector<float>> Sarax_dgy_proc{0};
    std::vector<std::vector<float>> P_insol_CEC_into_inclined_surface{0};

    std::vector<std::vector<float>> P_let_summ{0};
    std::vector<std::vector<float>> P_baz_summ{0};
    std::vector<std::vector<float>> P_nom_dgy{0};

    std::vector<std::vector<float>> P_loading_dgy{0};
    std::vector<std::vector<float>> P_etalon_YRNT{0};


    std::vector<std::vector<float>> P_min_dgy{0};
    std::vector<std::vector<float>> P_production_CEC{0};
    std::vector<std::vector<float>> P_production_CEC_into_min_dgy{0};
    std::vector<std::vector<float>> P_izlishki_production_CEC{0};
    std::vector<std::vector<float>> P_production_des_into_CEC{0};
    std::vector<std::vector<float>> P_loading_DGY_and_VIE{0};
    std::vector<std::vector<float>> P_etalon_YRNT_imp_DGY_and_VIE{0};
    std::vector<std::vector<float>> P_max_production_CEC_into_AKB{0};
    std::vector<std::vector<float>> P_production_CEC_AKB{0};
    std::vector<std::vector<float>> P_charging_AKB_of_CEC{0};
    std::vector<std::vector<float>> P_recharging_AKB{0};
    std::vector<std::vector<float>> P_production_CEC_into_AKB{0};
    std::vector<std::vector<float>> P_production_DES_into_AKB{0};
    std::vector<std::vector<float>> P_loading_DGY_into_SES_and_AKB{0};///надо отобразить
    std::vector<std::vector<float>> P_etalon_YRNT_imp_DGY{0};

    void input_P_ptreb(std::string name_base,std::string name_table){
        sqlite3 *db;

        sqlite3_open(std::string{name_base}.c_str(),&db);
        sqlite3_exec(db,std::string{"SELECT * from "+name_table}.c_str(), load_1, (void*)&P_ptreb, nullptr);
        sqlite3_close(db);
    };
    void input_P_YRNT(std::string name_base,std::string name_table){
        sqlite3 *db;
        // std::cout<<"PP"<<std::endl;
        sqlite3_open(std::string{name_base}.c_str(),&db);
        sqlite3_exec(db,std::string{"SELECT * from "+name_table}.c_str(), load_2, (void*)&P_YRNT_proc, nullptr);
        sqlite3_close(db);
    };
    void input_Import_dgy(std::string name_base,std::string name_table){
        sqlite3 *db;
         //std::cout<<"PP"<<std::endl;
        sqlite3_open(std::string{name_base}.c_str(),&db);
        sqlite3_exec(db,std::string{"SELECT * from "+name_table}.c_str(), load_3, (void*)&P_import_dgy, nullptr);
        sqlite3_close(db);
    };
    void input_russian_dgy(std::string name_base,std::string name_table){
        sqlite3 *db;
        // std::cout<<"PP"<<std::endl;
        sqlite3_open(std::string{name_base}.c_str(),&db);
        sqlite3_exec(db,std::string{"SELECT * from "+name_table}.c_str(), load_4, (void*)&P_russian_dgy, nullptr);
        sqlite3_close(db);
    };
    void input_Sarax_dgy(std::string name_base,std::string name_table){
        sqlite3 *db;
        // std::cout<<"PP"<<std::endl;
        sqlite3_open(std::string{name_base}.c_str(),&db);
        sqlite3_exec(db,std::string{"SELECT * from "+name_table}.c_str(), load_5, (void*)&Sarax_dgy_proc, nullptr);
        sqlite3_close(db);
    };
    void input_R_ptreb(std::string name_base,std::string name_table){
        sqlite3 *db;

        sqlite3_open(std::string{name_base}.c_str(),&db);
        sqlite3_exec(db,std::string{"SELECT * from "+name_table}.c_str(), load_1, (void*)&P_insol_CEC_into_inclined_surface, nullptr);
        sqlite3_close(db);
    };
};

struct Dgy_data{
    float P_dogovor=0.0f;///20

    float P_nom_baz=0.0f;///////////////////////////////////////////
    float P_nom_let=0.0f;///////////////////////////////////////////

    int N_rez_baz=0;
    int N_rez_let=0;

    float ZP_baz=0.0f;
    float ZP_let=0.0f;

    float ZP_new=0.0f;

    float VR_max=0.0f;
    float VR_max_proc=0.0f;

    float Pr_P=0.0f;
    float Pr_P_proc=0.0f;
};

struct Dgy_new_data{
    float production_dgy=0.0f;

    float utilization_average=0.0f;
    float utilization_min=0.0f;
    float utilization_max=0.0f;

    float Etalon_YRNT=0.0f;
    float Izm=0.0f;
    float Econom_oil=0.0f;

    std::vector<float> price_dgy_factoria;
    std::vector<float> dop_komplect_dgy;
    std::vector<float> kit_ZIP;
    std::vector<float> price_dgy_and_ZIP;

    std::vector<float> Pacetirovka;
    std::vector<float> price_b_m;

    float Sarex_dgy_factori=0.0f;
    float Sarex_dgy_factori_b_m=0.0f;

    float cout_P_baz=0.0f;
    float cout_P_let=0.0f;

    int replace_dgy=0;
    int new_b_m=0;

    float other_equipment=0.0f;
    float housing_production=0.0f;

    float PIR=0.0f;
    float CMP=0.0f;

    float logistics=0.0f;
    float other=0.0f;

    float Sarex_dgy=0.0f;
    float delta_price=0.0f;


    float max_load=0.0f;
    float min_load=0.0f;
    float  sr_load=0.0f;
};

struct Dgy_new_and_CEC_data{
    float spring_year_maximum_P=0.0f;
    float P_CEC=0.0f;
    float des_production=0.0f;
    float CEC_production=0.0f;
    float KIYM_CEC_year=0.0f;
    float sr_load_DGY_and_VIE=0.0f;

    float etalon_YRNT_IMP_dgy_and_vie=0.0f;
    float izmer=0.0f;
    float econom_oil=0.0f;
    float Carex_des_and_CEC=0.0f;
    float Proct_okup_bez_dt=0.0f;
};


void Imput_data::print(){
    int max_size_string_name=0;
    int max_size_string_namber=0;

    for(int i=0;i<15;i++){
        if(Name_setting[i].length()>max_size_string_name){
            max_size_string_name=Name_setting[i].length();
        }
        if(string_namber[i].length()>max_size_string_namber){
            max_size_string_namber=string_namber[i].length();
        }
    }

    std::cout<<max_size_string_name<<"|"<<max_size_string_namber<<std::endl;
    for(int i=0;i<19;i++){
        for(int j=Name_setting[i].length();j<max_size_string_name;j+=2){
            Name_setting[i]=" "+Name_setting[i];
        }
        for(int j=string_namber[i].length();j<max_size_string_namber;j+=2){
            string_namber[i]=" "+string_namber[i];
        }
        if(i<10){
            std::cout<<i<<"| "<<Name_setting[i]<<"|"<<string_namber[i]<<std::endl;
        }else{
            std::cout<<i<<"|"<<Name_setting[i]<<"|"<<string_namber[i]<<std::endl;
        }


    }
}

void Imput_data::input(std::string name){
    std::string line="";
    std::ifstream in(name);
    for(int i=0;i<20;i++){
        getline(in, line);
        int k=line.find('=');
        std::string lll="";
        Name_setting.push_back("");
        for(int p=0;p<k;p++){
              Name_setting[i]+=line[p];
        }
        for(int p=k+1;p<line.size();p++){
              lll+=line[p];
        }
        string_namber.push_back(lll);
        float f=std::stof(lll);

        switch (i){
            case 0: {P_DES=f;};break;
            case 1: {YRNT_DES=f;};break;
            case 2: {delta_cost_oil=f;};break;
            case 3: {price_DT=f;};break;
            case 4: {year_data[2016].year_max=f;};break;
            case 5: {year_data[2017].year_max=f;};break;
            case 6: {year_data[2018].year_max=f;};break;
            case 7: {year_data[2018].year_min=f;};break;
            case 8: {year_data[2018].summer_peak=f;};break;
            case 9: {year_data[2018].summer_decline=f;};break;
            case 10:{year_data[2018].winter_peak=f;};break;
            case 11:{year_data[2018].winter_decline=f;};break;
            case 12:{year_data[2018].deviations=f;};break;
            case 13:{P_under_concluded_agreements=f;};break;
            case 14:{coefficient_of_simultaneity=f;};break;

            case 15:{Own_needs=f;};break;
            case 16:{Optim_download=f;};break;
            case 17:{Min_ekcpel_download=f;};break;
            case 18:{Min_dop_download=f;};break;

            case 19:{Carex_cec=f;};break;
        }
        //std::cout<<Name_setting[i]<<"||"<<lll<<"|||"<<i<<"||"<<f<<std::endl;
    }
};

#endif // DATA_H

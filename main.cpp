#include <iostream>
#include <sqlite3.h>
#include <vector>

#include <Data.h>

const std::string PATCH="";


int main(){
    Imput_data data;
    P data_P;
    Dgy_data dgy;
    Dgy_new_data dgy_new;
    Dgy_new_and_CEC_data dgy_and_CEC;


    data_P.input_P_ptreb("data_P.db","P_MOMA");
    data_P.input_P_YRNT("data_P.db","DGY_rab_YRNT");
    data_P.input_Import_dgy("data_P.db","import_dgy");
    data_P.input_Sarax_dgy("data_P.db","Sarax_dgy_proc");
    data_P.input_R_ptreb("data_P.db","R_MOMA");

    data.input(PATCH+"data");

    //data.print();

    //////////////////////////////
    float P_new_max=std::max(std::max(data.year_data.at(2016).year_max,data.year_data.at(2017).year_max),data.year_data.at(2018).year_max);
    dgy.P_dogovor=data.coefficient_of_simultaneity*data.P_under_concluded_agreements+P_new_max;

    float dgy_nom_P[15]={1200,1000,500,300,250,200,150,120,100,80,60,40,30,20,10};

    for(int i=0;i<15;i++){
        if(dgy.P_dogovor/2.5f<dgy_nom_P[14-i]){
            dgy.P_nom_baz=dgy_nom_P[14-i];
            break;
        }
    }

    for(int i=0;i<15;i++){
        if(data.year_data.at(2018).summer_decline/(data.Optim_download*0.01)<dgy_nom_P[14-i]){
            dgy.P_nom_let=dgy_nom_P[14-i];
            break;
        }
    }

    if(static_cast<int>(dgy.P_nom_baz)==static_cast<int>(dgy.P_nom_let)){
        dgy.N_rez_baz=2;
    }else{
        dgy.N_rez_baz=1;
    }


    if(dgy.N_rez_baz==1){
        dgy.N_rez_let=1;
    }else{
        dgy.N_rez_let=0;
    }


    //std::cout<<dgy.P_nom_baz<<"|||"<<dgy.P_nom_let<<std::endl;

    dgy.ZP_baz=(static_cast<int>(P_new_max/dgy.P_nom_baz)+dgy.N_rez_baz+1)*dgy.P_nom_baz;

    if(dgy.N_rez_baz==2){
       dgy.ZP_let=0;
    }else{
       dgy.ZP_let=(static_cast<int>(data.year_data.at(2018).summer_decline/dgy.P_nom_let)+dgy.N_rez_baz+1)*dgy.P_nom_let;
    }

    dgy.ZP_new=dgy.ZP_baz+dgy.ZP_let;
    //std::cout<<"|dgy.ZP_new:|"<<dgy.ZP_new<<std::endl;

    dgy.VR_max=dgy.ZP_new-dgy.N_rez_baz*dgy.P_nom_baz-dgy.N_rez_let*dgy.P_nom_let-P_new_max;
    dgy.VR_max_proc=dgy.VR_max/(dgy.VR_max+P_new_max);

    dgy.Pr_P=dgy.ZP_new-P_new_max;
    dgy.Pr_P_proc=1+dgy.Pr_P/dgy.ZP_new;
    ///////////////////////////////////////////
    float t = 0.0f;
    float t_2=0.0f;
    float t_3=0.0f;
    float t_4=0.0f;
    float t_5=0.0f;
    float t_6=0.0f;

    float t_7=0.0f;
    float t_8=0.0f;
    float t_9=0.0f;
    float t_10=0.0f;

    int monthe[12]={31,
             28,
             31,
             30,
             31,
             30,
             31,
             31,
             30,
             31,
             30,
             31
};

    for(int i=2;i<8;i++){
        for(int j=0;j<24;j++){
            if(dgy_and_CEC.spring_year_maximum_P<data_P.P_ptreb[i][j]){
                dgy_and_CEC.spring_year_maximum_P=data_P.P_ptreb[i][j];
            }
        }
    }
    dgy_and_CEC.spring_year_maximum_P+=data.P_under_concluded_agreements;
    dgy_and_CEC.P_CEC=0.2*dgy_and_CEC.spring_year_maximum_P;


    for(int i=0;i<data_P.P_ptreb.size();i++){
        data_P.P_let_summ.push_back({0});
        data_P.P_baz_summ.push_back({0});
        data_P.P_nom_dgy.push_back({0});
        data_P.P_loading_dgy.push_back({0});
        data_P.P_etalon_YRNT.push_back({0});

        data_P.P_min_dgy.push_back({0});
        data_P.P_production_CEC.push_back({0});
        data_P.P_production_CEC_into_min_dgy.push_back({0});
        data_P.P_izlishki_production_CEC.push_back({0});
        data_P.P_production_des_into_CEC.push_back({0});
        data_P.P_loading_DGY_and_VIE.push_back({0});
        data_P.P_etalon_YRNT_imp_DGY_and_VIE.push_back({0});
        data_P.P_max_production_CEC_into_AKB.push_back({0});
        data_P.P_production_CEC_AKB.push_back({0});
        data_P.P_charging_AKB_of_CEC.push_back({0});
        data_P.P_recharging_AKB.push_back({0});
        data_P.P_production_CEC_into_AKB.push_back({0});
        data_P.P_production_DES_into_AKB.push_back({0});
        data_P.P_loading_DGY_into_SES_and_AKB.push_back({0});;///надо отобразить
        data_P.P_etalon_YRNT_imp_DGY.push_back({0});;


        data_P.P_let_summ.back().clear();
        data_P.P_baz_summ.back().clear();
        data_P.P_nom_dgy.back().clear();
        data_P.P_loading_dgy.back().clear();
        data_P.P_etalon_YRNT.back().clear();

        data_P.P_min_dgy.back().clear();
        data_P.P_production_CEC.back().clear();
        data_P.P_production_CEC_into_min_dgy.back().clear();
        data_P.P_izlishki_production_CEC.back().clear();
        data_P.P_production_des_into_CEC.back().clear();
        data_P.P_loading_DGY_and_VIE.back().clear();
        data_P.P_etalon_YRNT_imp_DGY_and_VIE.back().clear();
        data_P.P_max_production_CEC_into_AKB.back().clear();
        data_P.P_production_CEC_AKB.back().clear();
        data_P.P_charging_AKB_of_CEC.back().clear();
        data_P.P_recharging_AKB.back().clear();
        data_P.P_production_CEC_into_AKB.back().clear();
        data_P.P_production_DES_into_AKB.back().clear();
        data_P.P_loading_DGY_into_SES_and_AKB.back().clear();///надо отобразить
        data_P.P_etalon_YRNT_imp_DGY.back().clear();




        for(int j=0;j<data_P.P_ptreb[i].size();j++){
            t+=data_P.P_ptreb[i][j];
            t_7+=data_P.P_ptreb[i][j];
            //
            if((dgy.ZP_let*data.Optim_download*0.01)>data_P.P_ptreb[i][j]){
                data_P.P_let_summ.back().push_back((static_cast<int>(data_P.P_ptreb[i][j]/dgy.P_nom_let/(data.Optim_download*0.01))+1)*dgy.P_nom_let);
            }else{
                data_P.P_let_summ.back().push_back(0);
            }


            //std::cout<<data_P.P_let_summ.back().back()<<std::endl;
            //
            if((!(data_P.P_let_summ.back().back()>0)) &&
               ((dgy.ZP_baz*data.Optim_download*0.01)>data_P.P_ptreb[i][j])){
                data_P.P_baz_summ.back().push_back((static_cast<int>(data_P.P_ptreb[i][j]/dgy.P_nom_baz/(data.Optim_download*0.01))+1)*dgy.P_nom_baz);
            }else{
                data_P.P_baz_summ.back().push_back(0);
            }
            //
            if( data_P.P_baz_summ.back().back()>0){
                data_P.P_nom_dgy.back().push_back(dgy.P_nom_let);
            }else{
                data_P.P_nom_dgy.back().push_back(dgy.P_nom_baz);
            }

            if(data_P.P_let_summ.back().back()>0){
                data_P.P_loading_dgy.back().push_back(data_P.P_ptreb[i][j]/data_P.P_let_summ.back().back()*100);
            }else{
                data_P.P_loading_dgy.back().push_back(data_P.P_ptreb[i][j]/data_P.P_baz_summ.back().back()*100);
            }

            if(dgy_new.max_load<data_P.P_loading_dgy[i][j]){
                dgy_new.max_load=data_P.P_loading_dgy[i][j];
            }

            if(dgy_new.min_load>data_P.P_loading_dgy[i][j]){
                dgy_new.min_load=data_P.P_loading_dgy[i][j];
            }

            int k=0;
            switch (static_cast<int>(data_P.P_nom_dgy.back().back())) {
                case 1200:{k=0;}break;
                case 1000:{k=1;}break;
                case 500:{k=2;}break;
                case 300:{k=3;}break;
                case 250:{k=4;}break;
                case 200:{k=5;}break;
                case 150:{k=6;}break;
                case 120:{k=7;}break;
                case 100:{k=8;}break;
                case 80:{k=9;}break;
                case 60:{k=10;}break;
                case 40:{k=11;}break;
                case 30:{k=12;}break;
                case 20:{k=13;}break;
                case 10:{k=14;}break;
            }

            int f=0;
            switch (static_cast<int>(data_P.P_loading_dgy.back().back()*0.1)*10) {
                case 100:{f=8;}break;
                case 90:{f=7;}break;
                case 80:{f=6;}break;
                case 70:{f=5;}break;
                case 60:{f=4;}break;
                case 50:{f=3;}break;
                case 40:{f=2;}break;
                case 30:{f=1;}break;
                case 20:{f=0;}break;
                case 10:{f=9;}break;
            }

            data_P.P_etalon_YRNT.back().push_back(data_P.P_YRNT_proc[f][k]);
            t_2+=data_P.P_loading_dgy.back().back();

            //std::cout<<"||"<<data_P.P_ptreb[i][j]/data_P.P_loading_dgy.back().back()*data.Min_ekcpel_download<<std::endl;

            ////////////////
            if(data_P.P_loading_dgy.back().back()>=data.Min_ekcpel_download){
                data_P.P_min_dgy.back().push_back(data_P.P_ptreb[i][j]/data_P.P_loading_dgy.back().back()*data.Min_ekcpel_download);
            }else{
                data_P.P_min_dgy.back().push_back(data_P.P_ptreb[i][j]);
            }



            data_P.P_production_CEC.back().push_back(data_P.P_insol_CEC_into_inclined_surface[i][j]*dgy_and_CEC.P_CEC/1000.0f);

           if((data_P.P_ptreb[i][j]-data_P.P_min_dgy.back().back())<0){
                data_P.P_production_CEC_into_min_dgy.back().push_back(0);
            }else{
                if((data_P.P_ptreb[i][j]-data_P.P_min_dgy.back().back())>=data_P.P_production_CEC.back().back()){
                   data_P.P_production_CEC_into_min_dgy.back().push_back(data_P.P_production_CEC.back().back());
                }else{
                   data_P.P_production_CEC_into_min_dgy.back().push_back(data_P.P_ptreb[i][j]-data_P.P_min_dgy.back().back());
                }
            }


            data_P.P_izlishki_production_CEC.back().push_back(data_P.P_production_CEC.back().back()-data_P.P_production_CEC_into_min_dgy.back().back());
            //std::cout<<data_P.P_production_CEC_into_min_dgy.back().back()<<"^|^"<<data_P.P_production_CEC.back().back()<<"=>"<<data_P.P_izlishki_production_CEC.back().back()<<std::endl;

            data_P.P_production_des_into_CEC.back().push_back(data_P.P_ptreb[i][j]-data_P.P_production_CEC_into_min_dgy.back().back());

            if(data_P.P_let_summ.back().back()>0){
                data_P.P_loading_DGY_and_VIE.back().push_back(data_P.P_production_des_into_CEC.back().back()/data_P.P_let_summ.back().back()*100.0f);
            }else{
                data_P.P_loading_DGY_and_VIE.back().push_back(data_P.P_production_des_into_CEC.back().back()/data_P.P_baz_summ.back().back()*100.0f);
            }

            int r=0;
            switch (static_cast<int>(data_P.P_loading_DGY_and_VIE.back().back()*0.1)*10) {
                case 100:{r=8;}break;
                case 90:{r=7;}break;
                case 80:{r=6;}break;
                case 70:{r=5;}break;
                case 60:{r=4;}break;
                case 50:{r=3;}break;
                case 40:{r=2;}break;
                case 30:{r=1;}break;
                case 20:{r=0;}break;
                case 10:{r=9;}break;
            }

            //std::cout<<"|"<<data_P.P_YRNT_proc[f][k]<<"|"<<f<<"\\|/"<<r<<"|"<<data_P.P_YRNT_proc[r][k]<<std::endl;
            data_P.P_etalon_YRNT_imp_DGY_and_VIE.back().push_back(data_P.P_YRNT_proc[r][k]);
            //std::cout<<data_P.P_etalon_YRNT_imp_DGY_and_VIE.back().back()<<std::endl;

            t_6+=data_P.P_ptreb[i][j]*data_P.P_etalon_YRNT_imp_DGY_and_VIE.back().back();
            t_9+=data_P.P_loading_DGY_and_VIE.back().back();
            t_10+=data_P.P_production_CEC_into_min_dgy.back().back();
            t_3+=data_P.P_etalon_YRNT.back().back()*data_P.P_ptreb[i][j];
            //std::cout<<data_P.P_loading_dgy.back().back()<<"|"<<std::endl;
        }
        t_4+=t_10*monthe[i];
     // std::cout<<t_4<<"T_10:"<<t_10*monthe[i]<<std::endl;
        t_10=0.0f;

        t_5+=t_9*monthe[i];
        t_9=0.0f;

        t_8+=t_7*monthe[i];
        t_7=0.0f;
    }
    dgy_new.production_dgy=t_8;
    dgy_new.utilization_average=t_2/(24*12)*100;
    dgy_new.Etalon_YRNT=t_3/t;
    dgy_new.Izm=dgy_new.Etalon_YRNT/data.YRNT_DES;
    dgy_new.Econom_oil=(data.YRNT_DES-dgy_new.Etalon_YRNT)*dgy_new.production_dgy*data.price_DT/(1000*1000*1000);


    for(int i=0;i<data_P.P_loading_dgy.size();i++){
        for(int j=0;j<data_P.P_loading_dgy[i].size();j++){
            if(dgy_new.utilization_max<data_P.P_loading_dgy[i][j]){
            dgy_new.utilization_max=data_P.P_loading_dgy[i][j];
            }
            if(dgy_new.utilization_min>data_P.P_loading_dgy[i][j]){
            dgy_new.utilization_min=data_P.P_loading_dgy[i][j];
            }
        }
    }


    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[3][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[3][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[2][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[2][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[2][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[2][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[1][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[1][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[1][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[0][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[0][3]));
    dgy_new.price_dgy_factoria.push_back(static_cast<int>(data_P.P_import_dgy[0][3]));


    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[9][3]/1000.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[8][3]/500.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[8][3]/300.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[7][3]/250.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[7][3]/200.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[7][3]/150.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[7][3]/120.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[6][3]/100.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[6][3]/80.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[6][3]/60.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[6][3]/40.0f);
    dgy_new.kit_ZIP.push_back(data_P.P_import_dgy[6][3]/30.0f);

    dgy_new.cout_P_baz=dgy.ZP_baz/dgy.P_nom_baz;
    dgy_new.cout_P_let=dgy.ZP_let/dgy.P_nom_let;

    int k=0;
    switch (static_cast<int>(dgy.P_nom_baz)) {
        case 1200:{k=0;}break;
        case 1000:{k=1;}break;
        case 500:{k=2;}break;
        case 300:{k=3;}break;
        case 250:{k=4;}break;
        case 200:{k=5;}break;
        case 150:{k=6;}break;
        case 120:{k=7;}break;
        case 100:{k=8;}break;
        case 80:{k=9;}break;
        case 60:{k=10;}break;
        case 40:{k=11;}break;
        case 30:{k=12;}break;
        case 20:{k=13;}break;
        case 10:{k=14;}break;
    }

    int f=0;
    switch (static_cast<int>(dgy.P_nom_let)) {
        case 1200:{f=0;}break;
        case 1000:{f=1;}break;
        case 500:{f=2;}break;
        case 300:{f=3;}break;
        case 250:{f=4;}break;
        case 200:{f=5;}break;
        case 150:{f=6;}break;
        case 120:{f=7;}break;
        case 100:{f=8;}break;
        case 80:{f=9;}break;
        case 60:{f=10;}break;
        case 40:{f=11;}break;
        case 30:{f=12;}break;
        case 20:{f=13;}break;
        case 10:{f=14;}break;
    }

    dgy_new.Pacetirovka.push_back(0);
    dgy_new.Pacetirovka.push_back(0);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[12][3]/300);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[12][3]/250);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[12][3]/200);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[12][3]/150);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[12][3]/120);

    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[11][3]/100);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[11][3]/80);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[11][3]/60);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[11][3]/40);
    dgy_new.Pacetirovka.push_back(data_P.P_import_dgy[11][3]/30);


    for(int i=0;i<12;i++){
        dgy_new.dop_komplect_dgy.push_back(data_P.P_import_dgy[5][3]);
        dgy_new.price_dgy_and_ZIP.push_back(dgy_new.price_dgy_factoria[i]*(dgy_new.dop_komplect_dgy.back()*0.01+1)+dgy_new.kit_ZIP[i]);
        dgy_new.price_b_m.push_back(dgy_new.price_dgy_and_ZIP.back()+dgy_new.Pacetirovka[i]);
    }

    dgy_new.price_b_m[0]=0;
    dgy_new.price_b_m[1]=0;

    dgy_new.Sarex_dgy_factori=dgy_new.price_dgy_and_ZIP[k-1]*dgy_new.cout_P_baz*dgy.P_nom_baz+dgy_new.price_dgy_and_ZIP[f-1]*dgy_new.cout_P_let*dgy.P_nom_let;
    dgy_new.Sarex_dgy_factori_b_m=dgy_new.price_b_m[k-1]*dgy_new.cout_P_baz*dgy.P_nom_baz+dgy_new.price_b_m[f-1]*dgy_new.cout_P_let*dgy.P_nom_let;

    if(dgy.P_nom_baz>300){
        dgy_new.replace_dgy=1;
        dgy_new.new_b_m=0;
    }else{
        dgy_new.replace_dgy=0;
        dgy_new.new_b_m=1;
    }

    if(dgy_new.replace_dgy){
       dgy_new.other_equipment=dgy_new.Sarex_dgy_factori/(data_P.Sarax_dgy_proc[2][1]*0.01)*data_P.Sarax_dgy_proc[3][1]*0.01;
       dgy_new.housing_production=dgy_new.Sarex_dgy_factori/(data_P.Sarax_dgy_proc[2][1]*0.01)*data_P.Sarax_dgy_proc[4][1]*0.01;
       dgy_new.PIR=dgy_new.Sarex_dgy_factori/(data_P.Sarax_dgy_proc[1][1]*0.01)*data_P.Sarax_dgy_proc[0][1]*0.01;
       dgy_new.CMP=dgy_new.Sarex_dgy_factori/(data_P.Sarax_dgy_proc[1][1]*0.01)*data_P.Sarax_dgy_proc[5][1]*0.01;
       dgy_new.logistics=dgy_new.Sarex_dgy_factori/(data_P.Sarax_dgy_proc[1][1]*0.01)*data_P.Sarax_dgy_proc[6][1]*0.01;
       dgy_new.other=dgy_new.Sarex_dgy_factori/(data_P.Sarax_dgy_proc[1][1]*0.01)*data_P.Sarax_dgy_proc[7][1]*0.01;
    }else{
        dgy_new.other_equipment=dgy_new.Sarex_dgy_factori_b_m/(data_P.Sarax_dgy_proc[2][2]*0.01)*data_P.Sarax_dgy_proc[3][2]*0.01;
        dgy_new.housing_production=dgy_new.Sarex_dgy_factori_b_m/(data_P.Sarax_dgy_proc[2][2]*0.01)*data_P.Sarax_dgy_proc[4][2]*0.01;
        dgy_new.PIR=dgy_new.Sarex_dgy_factori_b_m/(data_P.Sarax_dgy_proc[1][2]*0.01)*data_P.Sarax_dgy_proc[0][2]*0.01;
        dgy_new.CMP=dgy_new.Sarex_dgy_factori_b_m/(data_P.Sarax_dgy_proc[1][2]*0.01)*data_P.Sarax_dgy_proc[5][2]*0.01;
        dgy_new.logistics=dgy_new.Sarex_dgy_factori_b_m/(data_P.Sarax_dgy_proc[1][2]*0.01)*data_P.Sarax_dgy_proc[6][2]*0.01;
        dgy_new.other=dgy_new.Sarex_dgy_factori_b_m/(data_P.Sarax_dgy_proc[1][2]*0.01)*data_P.Sarax_dgy_proc[7][2]*0.01;
    }
    if(data_P.Sarax_dgy_proc[2][1]*0.01*data_P.Sarax_dgy_proc[3][1]*0.01==0){
       dgy_new.other_equipment=0;
    }

    if(data_P.Sarax_dgy_proc[2][1]*0.01*data_P.Sarax_dgy_proc[4][1]*0.01==0){
       dgy_new.housing_production=0;
    }

    dgy_new.Sarex_dgy=dgy_new.Sarex_dgy_factori+dgy_new.Sarex_dgy_factori_b_m+dgy_new.other_equipment+dgy_new.housing_production+dgy_new.CMP+dgy_new.PIR+dgy_new.logistics+ dgy_new.other;
    dgy_new.delta_price=dgy_new.Sarex_dgy/dgy.ZP_new;
    //std::cout<<"|dgy_new.Sarex_dgy:|"<<dgy_new.Sarex_dgy<<std::endl;
    ////////////////////////////////////////////////////////////////////
    dgy_and_CEC.CEC_production=t_4/1000;
    dgy_and_CEC.des_production=dgy_new.production_dgy/1000-dgy_and_CEC.CEC_production;
    dgy_and_CEC.KIYM_CEC_year=(dgy_and_CEC.CEC_production/1000)/dgy_and_CEC.P_CEC/(8760*1000)*100;
    //dgy_and_CEC.sr_load_DGY_and_VIE=t_5;

    dgy_and_CEC.etalon_YRNT_IMP_dgy_and_vie=t_6/t;
    dgy_and_CEC.izmer=dgy_and_CEC.etalon_YRNT_IMP_dgy_and_vie/data.YRNT_DES;
    dgy_and_CEC.econom_oil=(data.YRNT_DES*dgy_new.production_dgy-dgy_and_CEC.etalon_YRNT_IMP_dgy_and_vie*dgy_and_CEC.des_production)*data.price_DT/(1000*1000*1000);
    dgy_and_CEC.Carex_des_and_CEC=dgy_new.Sarex_dgy/1000*dgy_and_CEC.P_CEC/1000;
    dgy_and_CEC.Proct_okup_bez_dt=dgy_and_CEC.Carex_des_and_CEC/dgy_and_CEC.econom_oil;
    //std::cout<<"|dgy_and_CEC.etalon_YRNT_IMP_dgy_and_vie:|"<<dgy_and_CEC.etalon_YRNT_IMP_dgy_and_vie<<"|"<<dgy_and_CEC.Proct_okup_bez_dt<<"|"<<std::endl;

//    struct economika{
//        float economia_oil=0.0f;
//        float
//    };


//    //Экономия топлива в год
//    for (int i = 0; i < n; i++) {
//        if (SVOD.B[i] = A3) {
//            economia_oil+=SVOD.CB[i];
//        }
//    }
//    //ДЭС
//    D5 = 0;
//    for (int i = 0; i < n; i++) {
//        if (SVOD.B[i] = A5) {
//            D5 = D5 + SVOD.AT[i];
//        }
//    }
//    //ВИЭ
//    D6 = 0;
//    for (int i = 0; i < n; i++) {
//        if (SVOD.B[i] = A6) {
//            D6 = D6 + SVOD.BO[i];
//        }
//    }
//    D6 = D6 * Dopush.D42 / 1000;
//    //АКБ
//    D7.1 = 0;
//    for (int i = 0; i < n; i++) {
//        if (SVOD.B[i] = A7) {
//            D7.1 = D7.1 + SVOD.BP[i];
//        }
//    }
//    D7.1 = D7.1 * Dopush.D43 / 1000;

//    D7.2 = 0;
//    for (int i = 0; i < n; i++) {
//        if (SVOD.B[i] = A3) {
//            D7.2 = D7.2 + SVOD.BQ[i];
//        }
//    }
//    D7.2 = D7.2 * Dopush.D44 / 1000;
//    D7 = D7.1 + D7;
//    //Opex ВИЭ+АКБ (в год)
//    D8 = (D7 + D6) * Dopush.;
//    //Доля кредита
//    D9 = Dopush.D5;
//    //Срок кредита
//    D10 = Dopush.D6;
//    //Ставка кредита
//    D11 = Dopush.D7;

//    // Инвестиции. Три массива ДГУ СЭС и АКБ, с количесвтом элементов до 27 (25 лет + нулевой год + нулевой элемент массива для решения задачи), где [i] - номер года. Причем первые элементы по единице, остальные равны нулю.
//    // Типа купили элементы только в первый год, в остальные не покупали, мб кст как оптимизацию можно будет рассмотреть возможность "докупки" элементов
//    //массивы назову DGU13[i]; CEC14[i]; AKB15[i]

//    //Эксплуатация объекта
//    DGU13.SUMM=0
//    explot16[1]=0
//    for (int i = 1; i < 27; i++) {
//        DGU13.SUMM = DGU13.SUMM + DGU13[i];
//        if (DGU13[i] = 0 && DGU13.SUMM > 0) {
//            Explot16[i] = 1;
//        }
//        else {
//            if (explot16[i - 1] = 1) {
//                explot16[i] = 1;
//            }
//            else {
//                explot16[i] = 0;
//            }
//        }
//    }
//    //Капитальные вложения
//    for (int i = 0; i < 26; i++) {
//        invest.17[i] = (DGU13[i + 1] * D5 + CEC14[i + 1] * D6 + AKB15[i + 1] * D7) * Dopush.15[i];
//        //Объем кредитования
//        volume.18[i] = D9 * invest.17[i];
//    }
//    //Экономия топлива + доходы от проекта (одинаковые массивы)
//    for (int i = 0; i < 25; i++) {
//        econom.20[i] = economia_oil * Dopush.13[i] * explot16[i + 2];
//    }
//    //Собственные средства
//    D22 = invest.17[1] - volume.18[1];
//    //Операционные затраты
//    for (int i = 0; i < 25; i++) {
//        waste.23[i] = D8 * Dopush.15[i] * explot16[i + 2];
//    }
//    //Выплаты по кредиту осн сумма
//    volume18.SUM = 0;
//    explot16.SUM = 0;
//    for (int i = 0; i < 25; i++) {
//        volume18.SUM = volume18[i] + volume18.SUM;
//        explot16.SUM = explot16[i] + explot16.SUM;
//        if (explot16.SUM >= D10) {
//            mainsum44[i] = 0;
//        }
//        else {
//            mainsum44[i] = (0 - volume.SUM) / D10;
//        }
//    }
//    // Процетнты
//    volume18.SUM = 0;
//    mainsum44.SUM = 0;
//    for (int i = 1; i < 27; i++) {
//        mainsum44.SUM = mainsum44[i - 1] + mainsum44.SUM;
//        volume18.SUM = volume18[i - 1] + volume18.SUM; //??
//        percent45[i] = 0 - (volume18.SUM + mainsum44.SUM) / D11;
//    }
//    //Первоначальная стоимость
//    E26 = D5;
//    //Амортизация + Накопленная амортизация + Балансовая стоимость на конец года + Балансовая стоимость на начало года
//    for (int i = 1; i < 25; i++) {
//        if (i < (i + Dopush.economia_oil9)) {
//            k = 1;
//        }
//        else {
//            k = 0;
//        }
//        Amor.28[i] = E26 / Dopush.economia_oil9 * k;
//        Amor.29= Amor.29 + Amor.28[i];
//        Amor.29[i] = Amor.29 + Amor.28[i];
//        Balanceend.30[i] = E26 - Amor.29[i];
//        Balancestart.27[i] =
//        Balancestart.27[1] = E26;
//    }

//    //Чистый денежный поток
//    for (int i = 1; i < 25; i++) {

//    Summa = 0;
//    for (i = 0; i < n; i++)
//        Summa = Summa + A[i];


//    if (num < 10) { // Если введенное число меньше 10.
//        cout << "Это число меньше 10." << endl;
//    }
//    else { // иначе
//        cout << "Это число больше либо равно 10." << endl;
//    }
//    }


    //Экспорт данных
    sqlite3 *db;
    sqlite3_open("data_P.db",&db);

    std::vector<std::string> sql_request;
    std::string defic="";
    std::string name_table="Export_A";
    std::string insert="INSERT INTO "+name_table
    +" (Znachenie) VALUES ";


    sql_request.push_back("(\""+defic+"\")");
    sql_request.push_back("(\""+defic+"\")");
    sql_request.push_back("(\""+std::to_string(data.P_DES)+"\")");
    sql_request.push_back("(\""+std::to_string(data.YRNT_DES)+"\")");
    sql_request.push_back("(\""+std::to_string(data.price_DT)+"\")");
    sql_request.push_back("(\""+defic+"\")");
    sql_request.push_back("(\""+defic+"\")");
    sql_request.push_back("(\""+defic+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2016).year_max)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2017).year_max)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2018).year_max)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2018).year_min)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2018).summer_decline)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2018).summer_peak)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2018).winter_decline)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2018).winter_peak)+"\")");
    sql_request.push_back("(\""+std::to_string(data.year_data.at(2018).deviations)+"\")");
    sql_request.push_back("(\""+std::to_string(data.P_under_concluded_agreements)+"\")");
    sql_request.push_back("(\""+std::to_string(data.coefficient_of_simultaneity)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.P_dogovor)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.N_rez_let)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.N_rez_baz)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.P_nom_let)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.P_nom_baz)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.ZP_baz)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.ZP_let)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.ZP_new)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.VR_max)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy.VR_max_proc*100)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.production_dgy/1000)+"\")");
    sql_request.push_back("(\""+std::to_string(0)+"\")");
    sql_request.push_back("(\""+std::to_string(0)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.sr_load)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.min_load)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.max_load)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.Etalon_YRNT)+"\")");
    sql_request.push_back("(\""+std::to_string(0)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.Econom_oil)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.Sarex_dgy/1000)+"\")");
    sql_request.push_back("(\""+std::to_string(0)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.replace_dgy)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_new.new_b_m)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.spring_year_maximum_P)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.P_CEC)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.des_production)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.CEC_production)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.KIYM_CEC_year)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.sr_load_DGY_and_VIE)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.etalon_YRNT_IMP_dgy_and_vie)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.izmer)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.econom_oil)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.Carex_des_and_CEC)+"\")");
    sql_request.push_back("(\""+std::to_string(dgy_and_CEC.Proct_okup_bez_dt)+"\"");


    for(int i=0;i<sql_request.size();i++){
    std::string sql_request_2="UPDATE Export SET Znachenie ="+sql_request[i]+" WHERE Field4="+std::to_string(i+1);
    sqlite3_exec(db,sql_request_2.c_str(), nullptr,nullptr, nullptr);
}

    return 0;
}
